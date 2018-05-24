#基本
CC = g++
CFLAGS=-Wall -Wno-deprecated -g -std=c++11
LN=/bin/ln -s 
AR=ar
CP=/bin/cp
RM=-/bin/rm -rf
ARCH=PC

# 二进制目标
BIN=test

#源文件目录
SrcDir= .
#头文件目录
#IncDir= . ../base ../base/jsoncpp ../base/pb/protocol ../base/pb
#连接库目录
#LibDir= ../base/ ../base/pb/lib/mac/ ../base/slog/lib/

SRCS=$(foreach dir,$(SrcDir),$(wildcard $(dir)/*.cpp))
INCS=$(foreach dir,$(IncDir),$(addprefix -I,$(dir)))
LINKS=$(foreach dir,$(LibDir),$(addprefix -L,$(dir)))
CFLAGS := $(CFLAGS) $(INCS)
LDFLAGS:= $(LINKS) $(LDFLAGS)

OBJS = $(SRCS:%.cpp=%.o)
.PHONY:all clean

all:$(BIN)
$(BIN):$(OBJS)
	$(CC) -o $(BIN) $(OBJS) $(LDFLAGS)
	@echo " OK! Complie $@ "

%.o:%.cpp
	@echo "[$(ARCH)] Compileing $@..."
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo "[$(ARCH)] Cleaning files..."
	$(RM) $(OBJS) $(BIN)
