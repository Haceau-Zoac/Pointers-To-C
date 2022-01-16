typedef struct {
  unsigned opcode : 16;
} misc;

typedef struct {
  unsigned opcode : 8;
  unsigned offset : 8;
} branch;

typedef struct {
  unsigned opcode : 10;
  unsigned dst_mode : 3;
  unsigned dst_reg : 3;
} sgl_op;

typedef struct {
  unsigned opcode : 8;
  unsigned src_reg : 3;
  unsigned dst_mode : 3;
  unsigned dst_reg : 3;
} reg_src;

typedef struct {
  unsigned opcode : 4;
  unsigned src_mode : 3;
  unsigned src_reg : 3;
  unsigned dst_mode : 3;
  unsigned dst_reg : 3;
} dbl_op;

typedef struct {
  unsigned short addr;
  misc misc;
  branch branch;
  sgl_op sgl_op;
  reg_src reg_src;
  dbl_op dbl_op;
} machine_inst;
