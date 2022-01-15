void strcpy(char* buffer, char const* string) {
  while ((*buffer++ = *string++) != '\0')
    ;
}
