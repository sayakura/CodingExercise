# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpeng <qpeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 18:31:08 by qpeng             #+#    #+#              #
#    Updated: 2019/07/17 19:09:10 by qpeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CUNIT_PATH=/nfs/2018/q/qpeng/.brew/Cellar/cunit/2.1-3/include

test:
	gcc $$(pkg-config --cflags --libs cunit) -I$(CUNIT_PATH) main.c
all: test

