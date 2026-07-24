#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct stat sb;
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    exit(-1);
  }
  char *path = argv[1];

  // Error handled here as stat gives -1 on errors
  if (stat(path, &sb) == -1) {
    perror("stat");
    exit(-1);
  }
  // Metadata
  int permissions;
  off_t file_size = sb.st_size;
  nlink_t hard_link_count = sb.st_nlink;
  uid_t owner_id = sb.st_uid;
  gid_t group_id = sb.st_gid;
  struct timespec last_access = sb.st_atimespec;
  struct timespec last_modified = sb.st_mtimespec;
  struct timespec last_changed = sb.st_ctimespec;

  // Leave below part for now for ai
  if (S_ISREG(sb.st_mode)) {
    printf("=== File Attributes for: %s ===\n", path);
    printf("File Type: Regular File\n");
    printf("Permissions: %o\n", sb.st_mode & 0777); // %o for octal mode
    printf("File Size: %lld bytes\n", (long long)file_size);
    printf("Hard Links Count: %d\n", hard_link_count);
    printf("Owner (UID): %d\n", owner_id);
    printf("Group (GID): %d\n", group_id);
    printf("Last Access Time: %s", ctime(&last_access.tv_sec));
    printf("Last Access Time: %s", ctime(&last_modified.tv_sec));
    printf("Status Change Time: %s", ctime(&last_changed.tv_sec));
  } else if (S_ISDIR(sb.st_mode)) {
    printf("=== File Attributes for: %s ===\n", path);
    printf("File Type: Directory\n");
    printf("Permissions: %o\n", sb.st_mode & 0777);
    printf("File Size: %lld bytes\n", (long long)file_size);
    printf("Hard Links Count: %d\n", hard_link_count);
    printf("Owner (UID): %d\n", owner_id);
    printf("Group (GID): %d\n", group_id);
    printf("Last Access Time: %s", ctime(&last_access.tv_sec));
    printf("Last Modified Time: %s", ctime(&last_modified.tv_sec));
    printf("Status Change Time: %s", ctime(&last_changed.tv_sec));
  } else {
    printf("Provided path is neither a file nor a directory\n");
    exit(-1);
  }
  return 0;
}