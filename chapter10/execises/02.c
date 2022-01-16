#define MAXNAME 20
#define MAXADDR 40
#define MAXMODL 20

typedef struct {
  char name[MAXNAME];
  char address[MAXADDR];
} customer;

typedef struct {
  float manufacturer_suggested_retail_price;
  float actual_selling_price;
  float sales_tax;
  float licensing_fee;
} full_cash_sales_info;

typedef struct {
  float manufacturer_suggested_retail_price;
  float actual_selling_price;
  float down_payment;
  float security_deposit;
  float monthly_payment;
  int lease_term;
} lease_info;

typedef struct {
  float manufacturer_suggested_retail_price;
  float actual_selling_price;
  float sales_tax;
  float licensing_fee;
  float down_payment;
  int loan_duration;
  float interest_rate;
  float monthly_payment;
  char name_of_bank[MAXNAME];
} loan_sales_info;

typedef struct {
  customer customer;
  char model[MAXMODL];
  union {
    full_cash_sales_info full_cash_sales_info;
    lease_info lease_info;
    loan_sales_info loan_sales_info;
  } additional_info;
} sales_record;
