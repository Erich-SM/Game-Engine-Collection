OUT = bin

SEARCHPATH += src
INC_SEARCHPATH += include
vpath %.c $(SEARCHPATH)
vpath %.h $(INC_SEARCHPATH)

DEPS += defs.h structs.h

_OBJS += m_utils.o m_physics.o
_OBJS += r_utils.o r_world.o
_OBJS += g_init.o i_input.o
_OBJS += g_main.o

OBJS = $(patsubst %,$(OUT)/%,$(_OBJS))

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
$(OUT)/%.o: %.c %.h $(DEPS)
	@mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<
	
# cleaning everything that can be automatically recreated with "make".
clean:
	$(RM) -rf $(OUT) $(PROG)
