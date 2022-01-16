#define MAXDATE 128

typedef struct {
  int area_code;
  int switchboard;
  int station_number;
} phone_number;

typedef struct {
  char datetime[MAXDATE];
  phone_number* caller;
  phone_number* answer;
  phone_number* pay_phone;
} long_distance_call_message;
