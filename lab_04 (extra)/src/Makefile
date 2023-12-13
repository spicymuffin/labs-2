####################################### BEG_3 ####

NAME        := main

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# SRC_DIR   source directory
# OBJ_DIR   object directory
# SRCS      source files
# OBJS      object files
#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags

SRC_DIR     := lib
OBJ_DIR     := lib/obj
SRCS        := \
	../main.cpp			\
	Actor/Actor.cpp     \
	Actor/Drama.cpp     \
	Actor/Suzi.cpp      \
	Actor/Yihyun.cpp    \
	Singer/BTS.cpp      \
	Singer/IU.cpp	    \
	Singer/Music.cpp    \
	Singer/Singer.cpp   \
	Singer/StayC.cpp    \
	Util/BestArtist.cpp \
	Artist.cpp          \
	Entertainer.cpp     \
	MBTI.cpp            

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := g++
CFLAGS      := -Wall
CPPFLAGS    := -I src/include

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   linking .o -> binary
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re
.SILENT:

####################################### END_3 ####

# all : $(TARGET)
	
# $(TARGET) :
	
# run :

# clean :
	