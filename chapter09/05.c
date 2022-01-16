void my_strncat(char* dest, char* src, int dest_len) {
  while (--dest_len > 0 && *dest != '\0')
    ++dest;
  if (dest_len <= 0) return;
  while (dest_len-- > 0 && (*dest++ = *src++) != '\0')
    ;
  *dest = '\0';
}
