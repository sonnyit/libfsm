/* Generated by lx */

#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>

#include LX_HEADER

static enum lx_native_token z0(struct lx_native_lx *lx);
static enum lx_native_token z1(struct lx_native_lx *lx);
static enum lx_native_token z2(struct lx_native_lx *lx);

#if __STDC_VERSION__ >= 199901L
inline
#endif
static int
lx_getc(struct lx_native_lx *lx)
{
	int c;

	assert(lx != NULL);
	assert(lx->lgetc != NULL);

	if (lx->c != EOF) {
		c = lx->c, lx->c = EOF;
	} else {
		c = lx->lgetc(lx);
		if (c == EOF) {
			return EOF;
		}
	}

	lx->end.byte++;
	lx->end.col++;

	if (c == '\n') {
		lx->end.line++;
		lx->end.col = 1;
	}

	return c;
}

#if __STDC_VERSION__ >= 199901L
inline
#endif
static void
lx_native_ungetc(struct lx_native_lx *lx, int c)
{
	assert(lx != NULL);
	assert(lx->c == EOF);

	lx->c = c;


	lx->end.byte--;
	lx->end.col--;

	if (c == '\n') {
		lx->end.line--;
		lx->end.col = 0; /* XXX: lost information */
	}
}

int
lx_native_dynpush(void *buf_opaque, char c)
{
	struct lx_dynbuf *t = buf_opaque;

	assert(t != NULL);

	if (t->p == t->a + t->len) {
		size_t len;
		ptrdiff_t off;
		char *tmp;

		if (t->len == 0) {
			assert(LX_DYN_LOW > 0);
			len = LX_DYN_LOW;
		} else {
			len = t->len * LX_DYN_FACTOR;
			if (len < t->len) {
				errno = ERANGE;
				return -1;
			}
		}

		off = t->p - t->a;
		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->p   = tmp + off;
		t->a   = tmp;
		t->len = len;
	}

	assert(t->p != NULL);
	assert(t->a != NULL);

	*t->p++ = c;

	return 0;
}

int
lx_native_dynclear(void *buf_opaque)
{
	struct lx_dynbuf *t = buf_opaque;

	assert(t != NULL);

	if (t->len > LX_DYN_HIGH) {
		size_t len;
		char *tmp;

		len = t->len / LX_DYN_FACTOR;

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->a   = tmp;
		t->len = len;
	}

	t->p = t->a;

	return 0;
}

void
lx_native_dynfree(void *buf_opaque)
{
	struct lx_dynbuf *t = buf_opaque;

	assert(t != NULL);

	free(t->a);
}
static enum lx_native_token
z0(struct lx_native_lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3, NONE
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx->buf_opaque);
	}

	state = NONE;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (state == NONE) {
			state = S0;
		}

		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case ',': state = S1; break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S2; break;
			case '}': state = S3; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S1: /* e.g. "," */
			lx_native_ungetc(lx, c); return TOK_SEP;

		case S2: /* e.g. "0" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': break;
			default:  lx_native_ungetc(lx, c); return TOK_COUNT;
			}
			break;

		case S3: /* e.g. "}" */
			lx_native_ungetc(lx, c); return lx->z = z2, TOK_CLOSECOUNT;

		default:
			; /* unreached */
		}

		if (lx->push != NULL) {
			if (-1 == lx->push(lx->buf_opaque, c)) {
				return TOK_ERROR;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case NONE: return TOK_EOF;
	case S1: return TOK_SEP;
	case S2: return TOK_COUNT;
	case S3: return TOK_CLOSECOUNT;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_native_token
z1(struct lx_native_lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, 
		S10, S11, S12, S13, S14, S15, S16, S17, S18, S19, 
		S20, S21, S22, S23, S24, S25, S26, S27, S28, S29, 
		S30, S31, S32, S33, S34, S35, S36, S37, S38, S39, 
		S40, S41, S42, S43, S44, S45, S46, S47, S48, S49, 
		S50, S51, S52, S53, S54, S55, S56, S57, S58, S59, 
		S60, S61, S62, S63, S64, S65, S66, S67, S68, S69, 
		S70, S71, S72, S73, S74, S75, S76, S77, S78, S79, 
		S80, S81, S82, S83, S84, S85, S86, S87, S88, S89, 
		S90, S91, S92, S93, S94, S95, S96, S97, S98, S99, 
		S100, S101, S102, S103, S104, S105, NONE
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx->buf_opaque);
	}

	state = NONE;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (state == NONE) {
			state = S0;
		}

		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t':
			case '\n':
			case '\v':
			case '\f':
			case '\r':
			case '\x0e':
			case '\x0f':
			case '\x10':
			case '\x11':
			case '\x12':
			case '\x13':
			case '\x14':
			case '\x15':
			case '\x16':
			case '\x17':
			case '\x18':
			case '\x19':
			case '\x1a':
			case '\x1b':
			case '\x1c':
			case '\x1d':
			case '\x1e':
			case '\x1f':
			case ' ':
			case '!':
			case '"':
			case '#':
			case '$':
			case '%':
			case '&':
			case '\'':
			case '(':
			case ')':
			case '*':
			case '+':
			case ',': state = S1; break;
			case '-': state = S2; break;
			case '.':
			case '\x2f':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case ':':
			case ';':
			case '<':
			case '=':
			case '>':
			case '?':
			case '@':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S1; break;
			case '[': state = S3; break;
			case '\\': state = S4; break;
			case ']': state = S5; break;
			case '^': state = S6; break;
			case '_':
			case '`':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case '{':
			case '|':
			case '}':
			case '~':
			case '\x7f':
			case 0x80:
			case 0x81:
			case 0x82:
			case 0x83:
			case 0x84:
			case 0x85:
			case 0x86:
			case 0x87:
			case 0x88:
			case 0x89:
			case 0x8a:
			case 0x8b:
			case 0x8c:
			case 0x8d:
			case 0x8e:
			case 0x8f:
			case 0x90:
			case 0x91:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0x95:
			case 0x96:
			case 0x97:
			case 0x98:
			case 0x99:
			case 0x9a:
			case 0x9b:
			case 0x9c:
			case 0x9d:
			case 0x9e:
			case 0x9f:
			case 0xa0:
			case 0xa1:
			case 0xa2:
			case 0xa3:
			case 0xa4:
			case 0xa5:
			case 0xa6:
			case 0xa7:
			case 0xa8:
			case 0xa9:
			case 0xaa:
			case 0xab:
			case 0xac:
			case 0xad:
			case 0xae:
			case 0xaf:
			case 0xb0:
			case 0xb1:
			case 0xb2:
			case 0xb3:
			case 0xb4:
			case 0xb5:
			case 0xb6:
			case 0xb7:
			case 0xb8:
			case 0xb9:
			case 0xba:
			case 0xbb:
			case 0xbc:
			case 0xbd:
			case 0xbe:
			case 0xbf:
			case 0xc0:
			case 0xc1:
			case 0xc2:
			case 0xc3:
			case 0xc4:
			case 0xc5:
			case 0xc6:
			case 0xc7:
			case 0xc8:
			case 0xc9:
			case 0xca:
			case 0xcb:
			case 0xcc:
			case 0xcd:
			case 0xce:
			case 0xcf:
			case 0xd0:
			case 0xd1:
			case 0xd2:
			case 0xd3:
			case 0xd4:
			case 0xd5:
			case 0xd6:
			case 0xd7:
			case 0xd8:
			case 0xd9:
			case 0xda:
			case 0xdb:
			case 0xdc:
			case 0xdd:
			case 0xde:
			case 0xdf:
			case 0xe0:
			case 0xe1:
			case 0xe2:
			case 0xe3:
			case 0xe4:
			case 0xe5:
			case 0xe6:
			case 0xe7:
			case 0xe8:
			case 0xe9:
			case 0xea:
			case 0xeb:
			case 0xec:
			case 0xed:
			case 0xee:
			case 0xef:
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff: state = S1; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S1: /* e.g. "a" */
			lx_native_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. "-" */
			lx_native_ungetc(lx, c); return TOK_RANGE;

		case S3: /* e.g. "[" */
			switch ((unsigned char) c) {
			case ':': state = S11; break;
			default:  lx_native_ungetc(lx, c); return TOK_CHAR;
			}
			break;

		case S4: /* e.g. "\\" */
			switch ((unsigned char) c) {
			case '-': state = S7; break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S8; break;
			case '\\': state = S7; break;
			case '^': state = S7; break;
			case 'f': state = S7; break;
			case 'n': state = S7; break;
			case 'r': state = S7; break;
			case 't': state = S7; break;
			case 'v': state = S7; break;
			case 'x': state = S9; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S5: /* e.g. "]" */
			lx_native_ungetc(lx, c); return lx->z = z2, TOK_CLOSEGROUP;

		case S6: /* e.g. "^" */
			lx_native_ungetc(lx, c); return TOK_INVERT;

		case S7: /* e.g. "\\f" */
			lx_native_ungetc(lx, c); return TOK_ESC;

		case S8: /* e.g. "\\0" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': break;
			default:  lx_native_ungetc(lx, c); return TOK_OCT;
			}
			break;

		case S9: /* e.g. "\\x" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S10; break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': state = S10; break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': state = S10; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S10: /* e.g. "\\xa" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': break;
			default:  lx_native_ungetc(lx, c); return TOK_HEX;
			}
			break;

		case S11: /* e.g. "[:" */
			switch ((unsigned char) c) {
			case 'a': state = S12; break;
			case 'b': state = S13; break;
			case 'c': state = S14; break;
			case 'd': state = S15; break;
			case 'g': state = S16; break;
			case 'l': state = S17; break;
			case 'p': state = S18; break;
			case 's': state = S19; break;
			case 'u': state = S20; break;
			case 'w': state = S21; break;
			case 'x': state = S22; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S12: /* e.g. "[:a" */
			switch ((unsigned char) c) {
			case 'l': state = S89; break;
			case 's': state = S90; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S13: /* e.g. "[:b" */
			switch ((unsigned char) c) {
			case 'l': state = S27; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S14: /* e.g. "[:c" */
			switch ((unsigned char) c) {
			case 'n': state = S44; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S15: /* e.g. "[:d" */
			switch ((unsigned char) c) {
			case 'i': state = S36; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S16: /* e.g. "[:g" */
			switch ((unsigned char) c) {
			case 'r': state = S71; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S17: /* e.g. "[:l" */
			switch ((unsigned char) c) {
			case 'o': state = S65; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S18: /* e.g. "[:p" */
			switch ((unsigned char) c) {
			case 'r': state = S77; break;
			case 'u': state = S78; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S19: /* e.g. "[:s" */
			switch ((unsigned char) c) {
			case 'p': state = S24; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S20: /* e.g. "[:u" */
			switch ((unsigned char) c) {
			case 'p': state = S23; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S21: /* e.g. "[:w" */
			switch ((unsigned char) c) {
			case 'o': state = S46; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S22: /* e.g. "[:x" */
			switch ((unsigned char) c) {
			case 'd': state = S25; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S23: /* e.g. "[:up" */
			switch ((unsigned char) c) {
			case 'p': state = S51; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S24: /* e.g. "[:sp" */
			switch ((unsigned char) c) {
			case 'a': state = S56; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S25: /* e.g. "[:xd" */
			switch ((unsigned char) c) {
			case 'i': state = S26; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S26: /* e.g. "[:xdi" */
			switch ((unsigned char) c) {
			case 'g': state = S29; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S27: /* e.g. "[:bl" */
			switch ((unsigned char) c) {
			case 'a': state = S28; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S28: /* e.g. "[:bla" */
			switch ((unsigned char) c) {
			case 'n': state = S34; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S29: /* e.g. "[:xdig" */
			switch ((unsigned char) c) {
			case 'i': state = S30; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S30: /* e.g. "[:xdigi" */
			switch ((unsigned char) c) {
			case 't': state = S31; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S31: /* e.g. "[:xdigit" */
			switch ((unsigned char) c) {
			case ':': state = S32; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S32: /* e.g. "[:xdigit:" */
			switch ((unsigned char) c) {
			case ']': state = S33; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S33: /* e.g. "[:xdigit:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_XDIGIT;

		case S34: /* e.g. "[:blan" */
			switch ((unsigned char) c) {
			case 'k': state = S35; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S35: /* e.g. "[:blank" */
			switch ((unsigned char) c) {
			case ':': state = S38; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S36: /* e.g. "[:di" */
			switch ((unsigned char) c) {
			case 'g': state = S37; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S37: /* e.g. "[:dig" */
			switch ((unsigned char) c) {
			case 'i': state = S40; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S38: /* e.g. "[:blank:" */
			switch ((unsigned char) c) {
			case ']': state = S39; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S39: /* e.g. "[:blank:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_BLANK;

		case S40: /* e.g. "[:digi" */
			switch ((unsigned char) c) {
			case 't': state = S41; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S41: /* e.g. "[:digit" */
			switch ((unsigned char) c) {
			case ':': state = S42; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S42: /* e.g. "[:digit:" */
			switch ((unsigned char) c) {
			case ']': state = S43; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S43: /* e.g. "[:digit:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_DIGIT;

		case S44: /* e.g. "[:cn" */
			switch ((unsigned char) c) {
			case 't': state = S45; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S45: /* e.g. "[:cnt" */
			switch ((unsigned char) c) {
			case 'r': state = S61; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S46: /* e.g. "[:wo" */
			switch ((unsigned char) c) {
			case 'r': state = S47; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S47: /* e.g. "[:wor" */
			switch ((unsigned char) c) {
			case 'd': state = S48; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S48: /* e.g. "[:word" */
			switch ((unsigned char) c) {
			case ':': state = S49; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S49: /* e.g. "[:word:" */
			switch ((unsigned char) c) {
			case ']': state = S50; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S50: /* e.g. "[:word:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_WORD;

		case S51: /* e.g. "[:upp" */
			switch ((unsigned char) c) {
			case 'e': state = S52; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S52: /* e.g. "[:uppe" */
			switch ((unsigned char) c) {
			case 'r': state = S53; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S53: /* e.g. "[:upper" */
			switch ((unsigned char) c) {
			case ':': state = S54; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S54: /* e.g. "[:upper:" */
			switch ((unsigned char) c) {
			case ']': state = S55; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S55: /* e.g. "[:upper:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_UPPER;

		case S56: /* e.g. "[:spa" */
			switch ((unsigned char) c) {
			case 'c': state = S57; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S57: /* e.g. "[:spac" */
			switch ((unsigned char) c) {
			case 'e': state = S58; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S58: /* e.g. "[:space" */
			switch ((unsigned char) c) {
			case ':': state = S59; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S59: /* e.g. "[:space:" */
			switch ((unsigned char) c) {
			case ']': state = S60; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S60: /* e.g. "[:space:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_SPACE;

		case S61: /* e.g. "[:cntr" */
			switch ((unsigned char) c) {
			case 'l': state = S62; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S62: /* e.g. "[:cntrl" */
			switch ((unsigned char) c) {
			case ':': state = S63; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S63: /* e.g. "[:cntrl:" */
			switch ((unsigned char) c) {
			case ']': state = S64; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S64: /* e.g. "[:cntrl:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_CNTRL;

		case S65: /* e.g. "[:lo" */
			switch ((unsigned char) c) {
			case 'w': state = S66; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S66: /* e.g. "[:low" */
			switch ((unsigned char) c) {
			case 'e': state = S67; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S67: /* e.g. "[:lowe" */
			switch ((unsigned char) c) {
			case 'r': state = S68; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S68: /* e.g. "[:lower" */
			switch ((unsigned char) c) {
			case ':': state = S69; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S69: /* e.g. "[:lower:" */
			switch ((unsigned char) c) {
			case ']': state = S70; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S70: /* e.g. "[:lower:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_LOWER;

		case S71: /* e.g. "[:gr" */
			switch ((unsigned char) c) {
			case 'a': state = S72; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S72: /* e.g. "[:gra" */
			switch ((unsigned char) c) {
			case 'p': state = S73; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S73: /* e.g. "[:grap" */
			switch ((unsigned char) c) {
			case 'h': state = S74; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S74: /* e.g. "[:graph" */
			switch ((unsigned char) c) {
			case ':': state = S75; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S75: /* e.g. "[:graph:" */
			switch ((unsigned char) c) {
			case ']': state = S76; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S76: /* e.g. "[:graph:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_GRAPH;

		case S77: /* e.g. "[:pr" */
			switch ((unsigned char) c) {
			case 'i': state = S79; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S78: /* e.g. "[:pu" */
			switch ((unsigned char) c) {
			case 'n': state = S80; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S79: /* e.g. "[:pri" */
			switch ((unsigned char) c) {
			case 'n': state = S81; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S80: /* e.g. "[:pun" */
			switch ((unsigned char) c) {
			case 'c': state = S85; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S81: /* e.g. "[:prin" */
			switch ((unsigned char) c) {
			case 't': state = S82; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S82: /* e.g. "[:print" */
			switch ((unsigned char) c) {
			case ':': state = S83; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S83: /* e.g. "[:print:" */
			switch ((unsigned char) c) {
			case ']': state = S84; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S84: /* e.g. "[:print:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_PRINT;

		case S85: /* e.g. "[:punc" */
			switch ((unsigned char) c) {
			case 't': state = S86; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S86: /* e.g. "[:punct" */
			switch ((unsigned char) c) {
			case ':': state = S87; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S87: /* e.g. "[:punct:" */
			switch ((unsigned char) c) {
			case ']': state = S88; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S88: /* e.g. "[:punct:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_PUNCT;

		case S89: /* e.g. "[:al" */
			switch ((unsigned char) c) {
			case 'n': state = S96; break;
			case 'p': state = S97; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S90: /* e.g. "[:as" */
			switch ((unsigned char) c) {
			case 'c': state = S91; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S91: /* e.g. "[:asc" */
			switch ((unsigned char) c) {
			case 'i': state = S92; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S92: /* e.g. "[:asci" */
			switch ((unsigned char) c) {
			case 'i': state = S93; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S93: /* e.g. "[:ascii" */
			switch ((unsigned char) c) {
			case ':': state = S94; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S94: /* e.g. "[:ascii:" */
			switch ((unsigned char) c) {
			case ']': state = S95; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S95: /* e.g. "[:ascii:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_ASCII;

		case S96: /* e.g. "[:aln" */
			switch ((unsigned char) c) {
			case 'u': state = S99; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S97: /* e.g. "[:alp" */
			switch ((unsigned char) c) {
			case 'h': state = S98; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S98: /* e.g. "[:alph" */
			switch ((unsigned char) c) {
			case 'a': state = S103; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S99: /* e.g. "[:alnu" */
			switch ((unsigned char) c) {
			case 'm': state = S100; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S100: /* e.g. "[:alnum" */
			switch ((unsigned char) c) {
			case ':': state = S101; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S101: /* e.g. "[:alnum:" */
			switch ((unsigned char) c) {
			case ']': state = S102; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S102: /* e.g. "[:alnum:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_ALNUM;

		case S103: /* e.g. "[:alpha" */
			switch ((unsigned char) c) {
			case ':': state = S104; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S104: /* e.g. "[:alpha:" */
			switch ((unsigned char) c) {
			case ']': state = S105; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S105: /* e.g. "[:alpha:]" */
			lx_native_ungetc(lx, c); return TOK_CLASS_ALPHA;

		default:
			; /* unreached */
		}

		if (lx->push != NULL) {
			if (-1 == lx->push(lx->buf_opaque, c)) {
				return TOK_ERROR;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case NONE: return TOK_EOF;
	case S1: return TOK_CHAR;
	case S2: return TOK_RANGE;
	case S3: return TOK_CHAR;
	case S5: return TOK_CLOSEGROUP;
	case S6: return TOK_INVERT;
	case S7: return TOK_ESC;
	case S8: return TOK_OCT;
	case S10: return TOK_HEX;
	case S33: return TOK_CLASS_XDIGIT;
	case S39: return TOK_CLASS_BLANK;
	case S43: return TOK_CLASS_DIGIT;
	case S50: return TOK_CLASS_WORD;
	case S55: return TOK_CLASS_UPPER;
	case S60: return TOK_CLASS_SPACE;
	case S64: return TOK_CLASS_CNTRL;
	case S70: return TOK_CLASS_LOWER;
	case S76: return TOK_CLASS_GRAPH;
	case S84: return TOK_CLASS_PRINT;
	case S88: return TOK_CLASS_PUNCT;
	case S95: return TOK_CLASS_ASCII;
	case S102: return TOK_CLASS_ALNUM;
	case S105: return TOK_CLASS_ALPHA;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_native_token
z2(struct lx_native_lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, 
		S10, S11, S12, S13, S14, S15, S16, S17, S18, S19, 
		S20, NONE
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx->buf_opaque);
	}

	state = NONE;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (state == NONE) {
			state = S0;
		}

		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t':
			case '\n':
			case '\v':
			case '\f':
			case '\r':
			case '\x0e':
			case '\x0f':
			case '\x10':
			case '\x11':
			case '\x12':
			case '\x13':
			case '\x14':
			case '\x15':
			case '\x16':
			case '\x17':
			case '\x18':
			case '\x19':
			case '\x1a':
			case '\x1b':
			case '\x1c':
			case '\x1d':
			case '\x1e':
			case '\x1f':
			case ' ':
			case '!':
			case '"':
			case '#': state = S1; break;
			case '$': state = S2; break;
			case '%':
			case '&':
			case '\'': state = S1; break;
			case '(': state = S3; break;
			case ')': state = S4; break;
			case '*': state = S5; break;
			case '+': state = S6; break;
			case ',':
			case '-': state = S1; break;
			case '.': state = S7; break;
			case '\x2f':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case ':':
			case ';':
			case '<':
			case '=':
			case '>': state = S1; break;
			case '?': state = S8; break;
			case '@':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S1; break;
			case '[': state = S9; break;
			case '\\': state = S10; break;
			case ']': state = S1; break;
			case '^': state = S11; break;
			case '_':
			case '`':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S1; break;
			case '{': state = S12; break;
			case '|': state = S13; break;
			case '}':
			case '~':
			case '\x7f':
			case 0x80:
			case 0x81:
			case 0x82:
			case 0x83:
			case 0x84:
			case 0x85:
			case 0x86:
			case 0x87:
			case 0x88:
			case 0x89:
			case 0x8a:
			case 0x8b:
			case 0x8c:
			case 0x8d:
			case 0x8e:
			case 0x8f:
			case 0x90:
			case 0x91:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0x95:
			case 0x96:
			case 0x97:
			case 0x98:
			case 0x99:
			case 0x9a:
			case 0x9b:
			case 0x9c:
			case 0x9d:
			case 0x9e:
			case 0x9f:
			case 0xa0:
			case 0xa1:
			case 0xa2:
			case 0xa3:
			case 0xa4:
			case 0xa5:
			case 0xa6:
			case 0xa7:
			case 0xa8:
			case 0xa9:
			case 0xaa:
			case 0xab:
			case 0xac:
			case 0xad:
			case 0xae:
			case 0xaf:
			case 0xb0:
			case 0xb1:
			case 0xb2:
			case 0xb3:
			case 0xb4:
			case 0xb5:
			case 0xb6:
			case 0xb7:
			case 0xb8:
			case 0xb9:
			case 0xba:
			case 0xbb:
			case 0xbc:
			case 0xbd:
			case 0xbe:
			case 0xbf:
			case 0xc0:
			case 0xc1:
			case 0xc2:
			case 0xc3:
			case 0xc4:
			case 0xc5:
			case 0xc6:
			case 0xc7:
			case 0xc8:
			case 0xc9:
			case 0xca:
			case 0xcb:
			case 0xcc:
			case 0xcd:
			case 0xce:
			case 0xcf:
			case 0xd0:
			case 0xd1:
			case 0xd2:
			case 0xd3:
			case 0xd4:
			case 0xd5:
			case 0xd6:
			case 0xd7:
			case 0xd8:
			case 0xd9:
			case 0xda:
			case 0xdb:
			case 0xdc:
			case 0xdd:
			case 0xde:
			case 0xdf:
			case 0xe0:
			case 0xe1:
			case 0xe2:
			case 0xe3:
			case 0xe4:
			case 0xe5:
			case 0xe6:
			case 0xe7:
			case 0xe8:
			case 0xe9:
			case 0xea:
			case 0xeb:
			case 0xec:
			case 0xed:
			case 0xee:
			case 0xef:
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff: state = S1; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S1: /* e.g. "a" */
			lx_native_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. "$" */
			lx_native_ungetc(lx, c); return TOK_END;

		case S3: /* e.g. "(" */
			lx_native_ungetc(lx, c); return TOK_OPENSUB;

		case S4: /* e.g. ")" */
			lx_native_ungetc(lx, c); return TOK_CLOSESUB;

		case S5: /* e.g. "*" */
			lx_native_ungetc(lx, c); return TOK_STAR;

		case S6: /* e.g. "+" */
			lx_native_ungetc(lx, c); return TOK_PLUS;

		case S7: /* e.g. "." */
			lx_native_ungetc(lx, c); return TOK_ANY;

		case S8: /* e.g. "?" */
			lx_native_ungetc(lx, c); return TOK_OPT;

		case S9: /* e.g. "[" */
			lx_native_ungetc(lx, c); return lx->z = z1, TOK_OPENGROUP;

		case S10: /* e.g. "\\" */
			switch ((unsigned char) c) {
			case '$': state = S14; break;
			case '(':
			case ')':
			case '*':
			case '+': state = S14; break;
			case '.': state = S14; break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S15; break;
			case '?': state = S14; break;
			case '[':
			case '\\': state = S14; break;
			case '^': state = S14; break;
			case 'f': state = S14; break;
			case 'n': state = S14; break;
			case 'r': state = S14; break;
			case 't': state = S14; break;
			case 'v': state = S14; break;
			case 'x': state = S16; break;
			case '{':
			case '|': state = S14; break;
			default:  lx_native_ungetc(lx, c); return TOK_CHAR;
			}
			break;

		case S11: /* e.g. "^" */
			lx_native_ungetc(lx, c); return TOK_START;

		case S12: /* e.g. "{" */
			lx_native_ungetc(lx, c); return lx->z = z0, TOK_OPENCOUNT;

		case S13: /* e.g. "|" */
			lx_native_ungetc(lx, c); return TOK_ALT;

		case S14: /* e.g. "\\f" */
			lx_native_ungetc(lx, c); return TOK_ESC;

		case S15: /* e.g. "\\0" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S19; break;
			default:  lx_native_ungetc(lx, c); return TOK_OCT;
			}
			break;

		case S16: /* e.g. "\\x" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S17; break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': state = S17; break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': state = S17; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S17: /* e.g. "\\xa" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S18; break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': state = S18; break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': state = S18; break;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
			break;

		case S18: /* e.g. "\\xaa" */
			lx_native_ungetc(lx, c); return TOK_HEX;

		case S19: /* e.g. "\\00" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S20; break;
			default:  lx_native_ungetc(lx, c); return TOK_OCT;
			}
			break;

		case S20: /* e.g. "\\000" */
			lx_native_ungetc(lx, c); return TOK_OCT;

		default:
			; /* unreached */
		}

		if (lx->push != NULL) {
			if (-1 == lx->push(lx->buf_opaque, c)) {
				return TOK_ERROR;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case NONE: return TOK_EOF;
	case S1: return TOK_CHAR;
	case S2: return TOK_END;
	case S3: return TOK_OPENSUB;
	case S4: return TOK_CLOSESUB;
	case S5: return TOK_STAR;
	case S6: return TOK_PLUS;
	case S7: return TOK_ANY;
	case S8: return TOK_OPT;
	case S9: return TOK_OPENGROUP;
	case S10: return TOK_CHAR;
	case S11: return TOK_START;
	case S12: return TOK_OPENCOUNT;
	case S13: return TOK_ALT;
	case S14: return TOK_ESC;
	case S15: return TOK_OCT;
	case S18: return TOK_HEX;
	case S19: return TOK_OCT;
	case S20: return TOK_OCT;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

const char *
lx_native_name(enum lx_native_token t)
{
	switch (t) {
	case TOK_COUNT: return "COUNT";
	case TOK_SEP: return "SEP";
	case TOK_CLOSECOUNT: return "CLOSECOUNT";
	case TOK_OPENCOUNT: return "OPENCOUNT";
	case TOK_CHAR: return "CHAR";
	case TOK_CLASS_XDIGIT: return "CLASS_XDIGIT";
	case TOK_CLASS_WORD: return "CLASS_WORD";
	case TOK_CLASS_UPPER: return "CLASS_UPPER";
	case TOK_CLASS_SPACE: return "CLASS_SPACE";
	case TOK_CLASS_PUNCT: return "CLASS_PUNCT";
	case TOK_CLASS_PRINT: return "CLASS_PRINT";
	case TOK_CLASS_LOWER: return "CLASS_LOWER";
	case TOK_CLASS_GRAPH: return "CLASS_GRAPH";
	case TOK_CLASS_DIGIT: return "CLASS_DIGIT";
	case TOK_CLASS_CNTRL: return "CLASS_CNTRL";
	case TOK_CLASS_BLANK: return "CLASS_BLANK";
	case TOK_CLASS_ASCII: return "CLASS_ASCII";
	case TOK_CLASS_ALPHA: return "CLASS_ALPHA";
	case TOK_CLASS_ALNUM: return "CLASS_ALNUM";
	case TOK_RANGE: return "RANGE";
	case TOK_INVERT: return "INVERT";
	case TOK_CLOSEGROUP: return "CLOSEGROUP";
	case TOK_OPENGROUP: return "OPENGROUP";
	case TOK_HEX: return "HEX";
	case TOK_OCT: return "OCT";
	case TOK_ESC: return "ESC";
	case TOK_ALT: return "ALT";
	case TOK_ANY: return "ANY";
	case TOK_PLUS: return "PLUS";
	case TOK_STAR: return "STAR";
	case TOK_OPT: return "OPT";
	case TOK_END: return "END";
	case TOK_START: return "START";
	case TOK_CLOSESUB: return "CLOSESUB";
	case TOK_OPENSUB: return "OPENSUB";
	case TOK_EOF:     return "EOF";
	case TOK_ERROR:   return "ERROR";
	case TOK_UNKNOWN: return "UNKNOWN";
	default: return "?";
	}
}

const char *
lx_native_example(enum lx_native_token (*z)(struct lx_native_lx *), enum lx_native_token t)
{
	assert(z != NULL);

	if (z == z0) {
		switch (t) {
		case TOK_COUNT: return "0";
		case TOK_SEP: return ",";
		case TOK_CLOSECOUNT: return "}";
		default: goto error;
		}
	} else
	if (z == z1) {
		switch (t) {
		case TOK_CHAR: return "a";
		case TOK_CLASS_XDIGIT: return "[:xdigit:]";
		case TOK_CLASS_WORD: return "[:word:]";
		case TOK_CLASS_UPPER: return "[:upper:]";
		case TOK_CLASS_SPACE: return "[:space:]";
		case TOK_CLASS_PUNCT: return "[:punct:]";
		case TOK_CLASS_PRINT: return "[:print:]";
		case TOK_CLASS_LOWER: return "[:lower:]";
		case TOK_CLASS_GRAPH: return "[:graph:]";
		case TOK_CLASS_DIGIT: return "[:digit:]";
		case TOK_CLASS_CNTRL: return "[:cntrl:]";
		case TOK_CLASS_BLANK: return "[:blank:]";
		case TOK_CLASS_ASCII: return "[:ascii:]";
		case TOK_CLASS_ALPHA: return "[:alpha:]";
		case TOK_CLASS_ALNUM: return "[:alnum:]";
		case TOK_RANGE: return "-";
		case TOK_INVERT: return "^";
		case TOK_CLOSEGROUP: return "]";
		case TOK_HEX: return "\\xa";
		case TOK_OCT: return "\\0";
		case TOK_ESC: return "\\f";
		default: goto error;
		}
	} else
	if (z == z2) {
		switch (t) {
		case TOK_OPENCOUNT: return "{";
		case TOK_CHAR: return "a";
		case TOK_OPENGROUP: return "[";
		case TOK_HEX: return "\\xaa";
		case TOK_OCT: return "\\0";
		case TOK_ESC: return "\\f";
		case TOK_ALT: return "|";
		case TOK_ANY: return ".";
		case TOK_PLUS: return "+";
		case TOK_STAR: return "*";
		case TOK_OPT: return "?";
		case TOK_END: return "$";
		case TOK_START: return "^";
		case TOK_CLOSESUB: return ")";
		case TOK_OPENSUB: return "(";
		default: goto error;
		}
	}

error:

	errno = EINVAL;
	return NULL;
}

void
lx_native_init(struct lx_native_lx *lx)
{
	static const struct lx_native_lx lx_default;

	assert(lx != NULL);

	*lx = lx_default;

	lx->c = EOF;
	lx->z = z2;

	lx->end.byte = 0;
	lx->end.line = 1;
	lx->end.col  = 1;
}

enum lx_native_token
lx_native_next(struct lx_native_lx *lx)
{
	enum lx_native_token t;

	assert(lx != NULL);
	assert(lx->z != NULL);

	if (lx->lgetc == NULL) {
		return TOK_EOF;
	}

	t = lx->z(lx);

	if (lx->push != NULL) {
		if (-1 == lx->push(lx->buf_opaque, '\0')) {
			return TOK_ERROR;
		}
	}

	return t;
}

