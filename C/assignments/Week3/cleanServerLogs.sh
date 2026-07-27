#!/bin/bash
# cleanup_logs.sh
# Script to sanitize sensitive data and update protocols in server_access.log

LOG_FILE="server_access.log"

if [[ -f "$LOG_FILE" ]]; then
    sed -E -i '/^#/d; s/([0-9]{4}-){3}[0-9]{4}|[0-9]{16}/XXXX-XXXX-XXXX-XXXX/g; s/HTTP\/1\.0/HTTP\/1.1/g' "$LOG_FILE"
    echo "Cleanup complete for $LOG_FILE"
else
    echo "Error: $LOG_FILE not found."
fi