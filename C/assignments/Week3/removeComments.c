#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    exit(-1);
  }
  char *path = argv[1];
  int fd = open(path, O_RDONLY, O_APPEND);
  if (fd == -1) {
    printf("Error opening file\n");
    exit(-1);
  }

  // Main business logic here
  int tempfd = open("temporary.c", O_CREAT | O_WRONLY | O_TRUNC,
                    S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  if (tempfd == -1) {
    printf("tempfd file issue while opening\n");
    perror("Opeing temporary file");
    exit(-1);
  }

  ssize_t bytes_read;
  char prev; // keeping a previous char for just in case right now
  char c;    // Reading one character at time

  // modes // states
  // Also we write into the file in all the cases except the comment case
  int code = 1, string = 0, charMode = 0, singleComment = 0, blockMode = 0,
      headerMode = 0;
  while ((bytes_read = read(fd, &c, 1)) > 0) {
    if (code == 1) {
      switch (c) {
      case '#':
        headerMode = 1;
        code = 0;
        if ((write(tempfd, &c, 1)) < 0) {
          perror("Write error in Code mode");
          exit(-1);
        }
        break;
      case '"':
        string = 1;
        code = 0;
        if ((write(tempfd, &c, 1)) < 0) {
          perror("Write error in Code mode");
          exit(-1);
        }
        break;
      case '\'':
        charMode = 1;
        code = 0;
        if ((write(tempfd, &c, 1)) < 0) {
          perror("Write error in Code mode");
          exit(-1);
        }
        break;
      case '/':
        // no write here
        if ((bytes_read = read(fd, &c, 1)) > 0) {
          if (c == '/') {
            singleComment = 1;
            code = 0;
          } else if (c == '*') {
            blockMode = 1;
            code = 0;
          } else {
            char t = '/';
            write(tempfd, &t, 1);
            if ((write(tempfd, &c, 1)) < 0) {
              perror("Write error in Code mode");
              exit(-1);
            }
          }
        }
        break;
      default:
        // simply write
        if ((write(tempfd, &c, 1)) < 0) {
          perror("Write error in Code mode");
          exit(-1);
        }
      }
    } else if (string == 1) {
      if (c == '\\') {
        if ((write(tempfd, &c, 1)) < 0) {
          perror("Write error in String mode");
          exit(-1);
        }
        if ((bytes_read = read(fd, &c, 1)) > 0) {
          if (write(tempfd, &c, 1) < 0) {
            perror("Write error in String mode");
            exit(-1);
          }
        }
        continue;
      } else if (c == '"') {
        string = 0;
        code = 1;
      }
      if ((write(tempfd, &c, 1)) < 0) {
        perror("Write error in String mode");
        exit(-1);
      }
    } else if (charMode == 1) {
      if (c == '\\') {
        if ((write(tempfd, &c, 1)) < 0) {
          perror("Write error in String mode");
          exit(-1);
        }
        if ((bytes_read = read(fd, &c, 1)) > 0) {
          if (write(tempfd, &c, 1) < 0) {
            perror("Write error in String mode");
            exit(-1);
          }
        }
        continue;
      } else if (c == '\'') {
        charMode = 0;
        code = 1;
      }
      if ((write(tempfd, &c, 1)) < 0) {
        perror("Write error in String mode");
        exit(-1);
      }
    } else if (singleComment == 1) {
      if (c == '\n') {
        singleComment = 0;
        code = 1;
        if ((write(tempfd, &c, 1)) < 0) {
          perror("Write error in String mode");
          exit(-1);
        }
      }

    } else if (headerMode == 1) {
      if (c == '\n') {
        headerMode = 0;
        code = 1;
      }
      if ((write(tempfd, &c, 1)) < 0) {
        perror("Write error in String mode");
        exit(-1);
      }
    } else if (blockMode == 1) {
      // inline block mode
      while (c == '*') {
        if ((bytes_read = read(fd, &c, 1)) > 0) {
          if (c == '/') {
            blockMode = 0;
            code = 1;
          }
        }
      }
    }
  }
  // closing file descriptors
  if (close(tempfd) == -1) {
    printf("tempfd file issue\n");
    printf("Error closing file\n");
    exit(-1);
  }

  if (bytes_read < 0) {
    printf("Error reading file\n");
    exit(-1);
  }
  if (close(fd) == -1) {
    printf("Error closing file\n");
    exit(-1);
  }
  printf("End of file\n");
  return 0;
}