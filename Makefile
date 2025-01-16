# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:29:48 by tcoeffet          #+#    #+#              #
#    Updated: 2025/01/16 17:26:32 by tcoeffet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

BONUS = 	checker

LIBFT =		./libft/libft.a

MAIN =		push_swap.c\

MAINOBJ = 	$(MAIN:.c=.o)

SOURCES = 	$(LIBFT)\
			push_swap_lst_1.c\
			push_swap_lst_2.c\
			push_swap_count.c\
			push_swap_parsing.c\
			push_swap_utils.c\
			push_swap_utils_2.c\
			push_swap_op_1.c\
			push_swap_op_2.c\
			push_swap_sort_1.c\
			push_swap_sort_2.c\
			push_swap_targets.c\
			error_check.c\
			error_check_utils.c\

MAIN_BONUS = checker_bonus.c\

MAINOBJBONUS = 	$(MAIN_BONUS:.c=.o)

SRC_BONUS =	checker_utils_bonus.c\

OBJ = 		$(SOURCES:.c=.o)

OBJBONUS = 	$(SRC_BONUS:.c=.o)

HEADERS =	./

FLAGS = 	-Wall -Werror -Wextra

CC = 		cc

MAKE_LIB = 	make -C ./libft all

TEST = 		a.out

ARG = "66 429 119 338 344 301 471 357 186 340 259 312 137 366 370 81 304 17 229 460 220 20 359 375 182 476 326 87 335 280 143 90 284 401 123 80 294 130 409 233 156 207 373 176 65 402 305 494 73 227 135 274 337 191 496 84 347 131 234 153 226 330 105 70 42 352 165 282 39 499 184 43 446 398 40 203 263 96 350 498 166 231 244 371 322 379 1 302 35 272 267 27 368 95 115 34 481 213 33 341 53 468 246 420 116 25 46 456 97 86 151 52 14 300 187 286 307 210 118 28 10 458 257 318 447 4 463 343 457 110 438 252 290 214 431 372 361 161 462 85 275 171 293 487 109 127 193 451 414 405 444 288 120 291 138 167 247 141 306 469 467 45 51 320 146 238 144 490 55 317 240 77 60 258 237 478 59 346 323 465 454 13 248 281 256 74 11 423 31 121 327 218 276 126 69 47 329 3 435 396 150 426 57 380 365 160 486 270 442 125 192 493 403 491 228 472 15 67 268 133 32 197 8 38 271 464 114 236 9 243 224 419 100 319 75 241 163 389 455 183 147 79 351 211 470 177 390 78 345 54 242 296 277 411 19 169 175 83 311 251 358 102 433 407 412 448 497 209 170 190 349 253 93 5 56 117 334 364 381 194 484 82 198 94 113 230 440 427 315 443 488 408 139 445 202 159 417 124 225 36 384 129 382 196 188 219 421 41 260 367 261 489 174 21 436 2 239 205 383 316 482 328 289 399 313 310 212 22 432 107 155 495 428 434 480 71 106 62 385 180 204 145 353 99 422 29 295 273 199 439 104 377 475 485 362 477 378 179 223 128 309 279 459 374 64 157 387 452 89 474 466 325 245 195 278 254 216 415 473 461 297 283 132 363 217 303 265 348 148 162 222 479 168 395 386 336 103 149 298 108 23 262 173 68 332 72 406 189 483 354 356 37 255 250 221 308 287 424 158 264 394 30 449 292 152 134 413 172 393 416 324 450 339 441 360 285 208 181 201 61 12 299 400 63 392 232 16 154 418 388 44 140 91 49 342 7 410 430 376 249 269 92 391 235 425 112 185 437 331 142 314 50 136 206 58 6 215 369 500 76 178 88 26 200 101 355 98 453 266 404 18 164 397 333 111 48 321 24 492 122 "

all :		$(NAME)


test :		$(TEST)
				./a.out $(ARG) > result.txt

$(TEST) : 	$(OBJ)
	$(CC) $(FLAGS) -I$(HEADERS) -g $(MAINOBJ) $(OBJ) $(LIBFT)

$(LIBFT) :
	$(MAKE_LIB)

$(NAME) : 	$(LIBFT) $(MAINOBJ) $(OBJ)
	$(CC) $(FLAGS) -g $(MAINOBJ) $(OBJ) $(LIBFT) -o $(NAME)

bonus :	$(BONUS)
		$(CC) $(FLAGS) -g  $(MAINOBJBONUS) $(OBJ) $(OBJBONUS) $(LIBFT) -o $(BONUS)
		make re
$(BONUS) : $(LIBFT) $(MAINOBJBONUS) $(OBJ) $(OBJBONUS)

ifneq ($(filter bonus, $(MAKECMDGOALS)),)
FLAGS += -DIS_CHECK=1
endif

$(OBJBONUS) : 
%.o : %.c
	$(CC) $(FLAGS) -c -g $< -o $@

clean : 
	rm -f $(MAINOBJ)
fclean : clean
	rm -f $(NAME) $(LIBFT) $(OBJ)
	make -C ./libft fclean
re : fclean all

cleanbonus : 
	rm -f $(OBJBONUS) $(MAINOBJ) $(MAINOBJBONUS)

fcleanbonus :	cleanbonus
	rm -f $(NAME) $(BONUS) $(LIBFT) $(OBJ) $(OBJBONUS)
	make -C ./libft fclean

rebonus : fcleanbonus all
