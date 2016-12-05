# Makefile pour le projet : POLYNOME
# Auteur : GIRAUD Pierre  / lundi 5 décembre 2016, 20:23:16 (UTC+0100)
# Ce document est sous Licence GPL v3
# voir : http://www.gnu.org/licenses/gpl-3.0.html

# Si il y a plusieurs répertoires qui contiennent des .c ou .h => modifier les 2 lignes suivantes
SOURCE_DIR = sources
INCLUDE_DIR = inc

BUILD_DIR = build
APPLICATION_NAME = POLYNOME
BINARY_NAME = ${BUILD_DIR}/${APPLICATION_NAME}
CC = gcc

# Commenter cette ligne si vous etes n'etes pas sous Mac OS X
#OS_FLAGS = -DMACOSX

LD_FLAGS = -lm

GCC_SECURITY_FLAGS = -fstack-protector -pie -fPIE -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security

CFLAGS = -I${INCLUDE_DIR} -Wall -ansi -pedantic -std=c99 ${OS_FLAGS} ${GCC_SECURITY_FLAGS}
CFLAGS_DEBUG = -g -DDEBUG


OBJS = ${SOURCE_DIR}/*.c

all: ${BINARY_NAME} ${BINARY_NAME}_debug

${BINARY_NAME}: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LD_FLAGS}

${BINARY_NAME}_debug: ${OBJS}
	${CC} ${CFLAGS} ${CFLAGS_DEBUG} -o $@ $^ ${LDFLAGS}

clean:
	${RM} *.o ${BINARY_NAME} ${BINARY_NAME}_debug
	${RM} -rf ${BINARY_NAME}_debug.dSYM

