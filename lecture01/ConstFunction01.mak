##
##  Makefile for C++ lecture
##
##  writen by mg.jeong<mg.jeong@gmail.com>
##

include ../common.mak

APPLICATION_NAME		= ConstFunction01
APPLICATION_SRC_PATH	= .
APPLICATION_INC_PATH	= .
APPLICATION_OUT_PATH	= .
APPLICATION_OBJ_PATH	= .obj

APPLICATION_SRCS		= ConstFunction01.cpp

APPLICATION_OBJS		= $(APPLICATION_SRCS:%.cpp=$(APPLICATION_OBJ_PATH)/%.o)

CFLAGS					= -g -c -Wall

LFLAGS					=

IFLAGS					= -I$(APPLICATION_INC_PATH)

DFLAGS					= -DLINUX

vpath	%.cpp $(APPLICATION_SRC_PATH)


TARGET_NAME				= $(APPLICATION_NAME)
TARGET					= ./$(TARGET_NAME)


$(APPLICATION_OBJ_PATH)/%.o : %.cpp
	@$(MAKE_OBJ_PATH)
	$(CXX) -o $@ $(CFLAGS) $(DFLAGS) $(IFLAGS) $<

all : $(TARGET)
	@echo " "
	@echo "Building application is done successfully...^^"
	@echo " "

$(TARGET) : $(APPLICATION_OBJS)
	$(CXX) -o $@ $(APPLICATION_OBJS) $(LFLAGS)
	
clean :
	$(RM) $(APPLICATION_OBJS) $(TARGET)



define MAKE_OBJ_PATH
	@if [ ! -d $(APPLICATION_OBJ_PATH) ]; then \
	mkdir $(APPLICATION_OBJ_PATH); \
	fi
endef

.PHONY: all clean install


