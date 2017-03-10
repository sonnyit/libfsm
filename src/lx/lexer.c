/* Generated by lx */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include LX_HEADER

static enum lx_token z0(struct lx *lx);
static enum lx_token z1(struct lx *lx);
static enum lx_token z2(struct lx *lx);
static enum lx_token z3(struct lx *lx);
static enum lx_token z4(struct lx *lx);

#if __STDC_VERSION__ >= 199901L
inline
#endif
static int
lx_getc(struct lx *lx)
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
lx_ungetc(struct lx *lx, int c)
{
	assert(lx != NULL);
	assert(lx->c == EOF);

	lx->c = c;

	if (lx->pop != NULL) {
		lx->pop(lx);
	}

	lx->end.byte--;
	lx->end.col--;

	if (c == '\n') {
		lx->end.line--;
		lx->end.col = 0; /* XXX: lost information */
	}
}

int
lx_fgetc(struct lx *lx)
{
	assert(lx != NULL);
	assert(lx->opaque != NULL);

	return fgetc(lx->opaque);
}

int
lx_dynpush(struct lx *lx, char c)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);
	assert(c != EOF);

	t = lx->buf;

	assert(t != NULL);

	if (t->p == t->a + t->len) {
		size_t len;
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

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->p   = tmp + (t->p - t->a);
		t->a   = tmp;
		t->len = len;
	}

	assert(t->p != NULL);
	assert(t->a != NULL);

	*t->p++ = c;

	return 0;
}

void
lx_dynpop(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);
	assert(t->a != NULL);
	assert(t->p >= t->a);

	if (t->p == t->a) {
		return;
	}

	t->p--;
}

int
lx_dynclear(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

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
lx_dynfree(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	free(t->a);
}
static enum lx_token
z0(struct lx *lx)
{
	int c;

	enum {
		S0, S1, S2
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch (c) {
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
			case ',':
			case '-':
			case '.': state = S1; continue;
			case '\x2f': state = S2; continue;
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
			case 'Z':
			case '[':
			case '\\':
			case ']':
			case '^':
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
			case '\x80':
			case '\x81':
			case '\x82':
			case '\x83':
			case '\x84':
			case '\x85':
			case '\x86':
			case '\x87':
			case '\x88':
			case '\x89':
			case '\x8a':
			case '\x8b':
			case '\x8c':
			case '\x8d':
			case '\x8e':
			case '\x8f':
			case '\x90':
			case '\x91':
			case '\x92':
			case '\x93':
			case '\x94':
			case '\x95':
			case '\x96':
			case '\x97':
			case '\x98':
			case '\x99':
			case '\x9a':
			case '\x9b':
			case '\x9c':
			case '\x9d':
			case '\x9e':
			case '\x9f':
			case '\xa0':
			case '\xa1':
			case '\xa2':
			case '\xa3':
			case '\xa4':
			case '\xa5':
			case '\xa6':
			case '\xa7':
			case '\xa8':
			case '\xa9':
			case '\xaa':
			case '\xab':
			case '\xac':
			case '\xad':
			case '\xae':
			case '\xaf':
			case '\xb0':
			case '\xb1':
			case '\xb2':
			case '\xb3':
			case '\xb4':
			case '\xb5':
			case '\xb6':
			case '\xb7':
			case '\xb8':
			case '\xb9':
			case '\xba':
			case '\xbb':
			case '\xbc':
			case '\xbd':
			case '\xbe':
			case '\xbf':
			case '\xc0':
			case '\xc1':
			case '\xc2':
			case '\xc3':
			case '\xc4':
			case '\xc5':
			case '\xc6':
			case '\xc7':
			case '\xc8':
			case '\xc9':
			case '\xca':
			case '\xcb':
			case '\xcc':
			case '\xcd':
			case '\xce':
			case '\xcf':
			case '\xd0':
			case '\xd1':
			case '\xd2':
			case '\xd3':
			case '\xd4':
			case '\xd5':
			case '\xd6':
			case '\xd7':
			case '\xd8':
			case '\xd9':
			case '\xda':
			case '\xdb':
			case '\xdc':
			case '\xdd':
			case '\xde':
			case '\xdf':
			case '\xe0':
			case '\xe1':
			case '\xe2':
			case '\xe3':
			case '\xe4':
			case '\xe5':
			case '\xe6':
			case '\xe7':
			case '\xe8':
			case '\xe9':
			case '\xea':
			case '\xeb':
			case '\xec':
			case '\xed':
			case '\xee':
			case '\xef':
			case '\xf0':
			case '\xf1':
			case '\xf2':
			case '\xf3':
			case '\xf4':
			case '\xf5':
			case '\xf6':
			case '\xf7':
			case '\xf8':
			case '\xf9':
			case '\xfa':
			case '\xfb':
			case '\xfc':
			case '\xfd':
			case '\xfe':
			case '\xff': state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. "\x2f" */
			switch (c) {
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
			case 'Z': continue;
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
			case 'z': continue;
			default:  lx_ungetc(lx, c); return lx->z = z4, TOK_RE;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_CHAR;
	case S2: return TOK_RE;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z1(struct lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3, S4, S5, S6, S7
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch (c) {
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
			case '!': state = S1; continue;
			case '"': state = S2; continue;
			case '#':
			case '$':
			case '%':
			case '&':
			case '\'':
			case '(':
			case ')':
			case '*':
			case '+':
			case ',':
			case '-':
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
			case 'Z':
			case '[': state = S1; continue;
			case '\\': state = S3; continue;
			case ']':
			case '^':
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
			case '\x80':
			case '\x81':
			case '\x82':
			case '\x83':
			case '\x84':
			case '\x85':
			case '\x86':
			case '\x87':
			case '\x88':
			case '\x89':
			case '\x8a':
			case '\x8b':
			case '\x8c':
			case '\x8d':
			case '\x8e':
			case '\x8f':
			case '\x90':
			case '\x91':
			case '\x92':
			case '\x93':
			case '\x94':
			case '\x95':
			case '\x96':
			case '\x97':
			case '\x98':
			case '\x99':
			case '\x9a':
			case '\x9b':
			case '\x9c':
			case '\x9d':
			case '\x9e':
			case '\x9f':
			case '\xa0':
			case '\xa1':
			case '\xa2':
			case '\xa3':
			case '\xa4':
			case '\xa5':
			case '\xa6':
			case '\xa7':
			case '\xa8':
			case '\xa9':
			case '\xaa':
			case '\xab':
			case '\xac':
			case '\xad':
			case '\xae':
			case '\xaf':
			case '\xb0':
			case '\xb1':
			case '\xb2':
			case '\xb3':
			case '\xb4':
			case '\xb5':
			case '\xb6':
			case '\xb7':
			case '\xb8':
			case '\xb9':
			case '\xba':
			case '\xbb':
			case '\xbc':
			case '\xbd':
			case '\xbe':
			case '\xbf':
			case '\xc0':
			case '\xc1':
			case '\xc2':
			case '\xc3':
			case '\xc4':
			case '\xc5':
			case '\xc6':
			case '\xc7':
			case '\xc8':
			case '\xc9':
			case '\xca':
			case '\xcb':
			case '\xcc':
			case '\xcd':
			case '\xce':
			case '\xcf':
			case '\xd0':
			case '\xd1':
			case '\xd2':
			case '\xd3':
			case '\xd4':
			case '\xd5':
			case '\xd6':
			case '\xd7':
			case '\xd8':
			case '\xd9':
			case '\xda':
			case '\xdb':
			case '\xdc':
			case '\xdd':
			case '\xde':
			case '\xdf':
			case '\xe0':
			case '\xe1':
			case '\xe2':
			case '\xe3':
			case '\xe4':
			case '\xe5':
			case '\xe6':
			case '\xe7':
			case '\xe8':
			case '\xe9':
			case '\xea':
			case '\xeb':
			case '\xec':
			case '\xed':
			case '\xee':
			case '\xef':
			case '\xf0':
			case '\xf1':
			case '\xf2':
			case '\xf3':
			case '\xf4':
			case '\xf5':
			case '\xf6':
			case '\xf7':
			case '\xf8':
			case '\xf9':
			case '\xfa':
			case '\xfb':
			case '\xfc':
			case '\xfd':
			case '\xfe':
			case '\xff': state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. """ */
			lx_ungetc(lx, c); return lx->z = z4, TOK_STR;

		case S3: /* e.g. "\\" */
			switch (c) {
			case '"': state = S4; continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S5; continue;
			case '\\': state = S4; continue;
			case 'f': state = S4; continue;
			case 'n': state = S4; continue;
			case 'r': state = S4; continue;
			case 't': state = S4; continue;
			case 'v': state = S4; continue;
			case 'x': state = S6; continue;
			default:  lx_ungetc(lx, c); return TOK_CHAR;
			}

		case S4: /* e.g. "\\f" */
			lx_ungetc(lx, c); return TOK_ESC;

		case S5: /* e.g. "\\0" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': continue;
			default:  lx_ungetc(lx, c); return TOK_OCT;
			}

		case S6: /* e.g. "\\x" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': state = S7; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S7: /* e.g. "\\xa" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': continue;
			default:  lx_ungetc(lx, c); return TOK_HEX;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_CHAR;
	case S2: return TOK_STR;
	case S3: return TOK_CHAR;
	case S4: return TOK_ESC;
	case S5: return TOK_OCT;
	case S7: return TOK_HEX;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z2(struct lx *lx)
{
	int c;

	enum {
		S0, S1, S2
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch (c) {
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
			case '&': state = S1; continue;
			case '\'': state = S2; continue;
			case '(':
			case ')':
			case '*':
			case '+':
			case ',':
			case '-':
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
			case 'Z':
			case '[':
			case '\\':
			case ']':
			case '^':
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
			case '\x80':
			case '\x81':
			case '\x82':
			case '\x83':
			case '\x84':
			case '\x85':
			case '\x86':
			case '\x87':
			case '\x88':
			case '\x89':
			case '\x8a':
			case '\x8b':
			case '\x8c':
			case '\x8d':
			case '\x8e':
			case '\x8f':
			case '\x90':
			case '\x91':
			case '\x92':
			case '\x93':
			case '\x94':
			case '\x95':
			case '\x96':
			case '\x97':
			case '\x98':
			case '\x99':
			case '\x9a':
			case '\x9b':
			case '\x9c':
			case '\x9d':
			case '\x9e':
			case '\x9f':
			case '\xa0':
			case '\xa1':
			case '\xa2':
			case '\xa3':
			case '\xa4':
			case '\xa5':
			case '\xa6':
			case '\xa7':
			case '\xa8':
			case '\xa9':
			case '\xaa':
			case '\xab':
			case '\xac':
			case '\xad':
			case '\xae':
			case '\xaf':
			case '\xb0':
			case '\xb1':
			case '\xb2':
			case '\xb3':
			case '\xb4':
			case '\xb5':
			case '\xb6':
			case '\xb7':
			case '\xb8':
			case '\xb9':
			case '\xba':
			case '\xbb':
			case '\xbc':
			case '\xbd':
			case '\xbe':
			case '\xbf':
			case '\xc0':
			case '\xc1':
			case '\xc2':
			case '\xc3':
			case '\xc4':
			case '\xc5':
			case '\xc6':
			case '\xc7':
			case '\xc8':
			case '\xc9':
			case '\xca':
			case '\xcb':
			case '\xcc':
			case '\xcd':
			case '\xce':
			case '\xcf':
			case '\xd0':
			case '\xd1':
			case '\xd2':
			case '\xd3':
			case '\xd4':
			case '\xd5':
			case '\xd6':
			case '\xd7':
			case '\xd8':
			case '\xd9':
			case '\xda':
			case '\xdb':
			case '\xdc':
			case '\xdd':
			case '\xde':
			case '\xdf':
			case '\xe0':
			case '\xe1':
			case '\xe2':
			case '\xe3':
			case '\xe4':
			case '\xe5':
			case '\xe6':
			case '\xe7':
			case '\xe8':
			case '\xe9':
			case '\xea':
			case '\xeb':
			case '\xec':
			case '\xed':
			case '\xee':
			case '\xef':
			case '\xf0':
			case '\xf1':
			case '\xf2':
			case '\xf3':
			case '\xf4':
			case '\xf5':
			case '\xf6':
			case '\xf7':
			case '\xf8':
			case '\xf9':
			case '\xfa':
			case '\xfb':
			case '\xfc':
			case '\xfd':
			case '\xfe':
			case '\xff': state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. "\'" */
			lx_ungetc(lx, c); return lx->z = z4, TOK_STR;
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_CHAR;
	case S2: return TOK_STR;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z3(struct lx *lx)
{
	int c;

	enum {
		S0, S1, S2
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		switch (state) {
		case S0:
		case S1:
		case S2:
			break;

		default:
			if (lx->push != NULL) {
				if (-1 == lx->push(lx, c)) {
					return TOK_ERROR;
				}
			}
			break;

		}

		switch (state) {
		case S0: /* start */
			switch (c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t': state = S1; continue;
			case '\n': state = S2; continue;
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
			case ',':
			case '-':
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
			case 'Z':
			case '[':
			case '\\':
			case ']':
			case '^':
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
			case '\x80':
			case '\x81':
			case '\x82':
			case '\x83':
			case '\x84':
			case '\x85':
			case '\x86':
			case '\x87':
			case '\x88':
			case '\x89':
			case '\x8a':
			case '\x8b':
			case '\x8c':
			case '\x8d':
			case '\x8e':
			case '\x8f':
			case '\x90':
			case '\x91':
			case '\x92':
			case '\x93':
			case '\x94':
			case '\x95':
			case '\x96':
			case '\x97':
			case '\x98':
			case '\x99':
			case '\x9a':
			case '\x9b':
			case '\x9c':
			case '\x9d':
			case '\x9e':
			case '\x9f':
			case '\xa0':
			case '\xa1':
			case '\xa2':
			case '\xa3':
			case '\xa4':
			case '\xa5':
			case '\xa6':
			case '\xa7':
			case '\xa8':
			case '\xa9':
			case '\xaa':
			case '\xab':
			case '\xac':
			case '\xad':
			case '\xae':
			case '\xaf':
			case '\xb0':
			case '\xb1':
			case '\xb2':
			case '\xb3':
			case '\xb4':
			case '\xb5':
			case '\xb6':
			case '\xb7':
			case '\xb8':
			case '\xb9':
			case '\xba':
			case '\xbb':
			case '\xbc':
			case '\xbd':
			case '\xbe':
			case '\xbf':
			case '\xc0':
			case '\xc1':
			case '\xc2':
			case '\xc3':
			case '\xc4':
			case '\xc5':
			case '\xc6':
			case '\xc7':
			case '\xc8':
			case '\xc9':
			case '\xca':
			case '\xcb':
			case '\xcc':
			case '\xcd':
			case '\xce':
			case '\xcf':
			case '\xd0':
			case '\xd1':
			case '\xd2':
			case '\xd3':
			case '\xd4':
			case '\xd5':
			case '\xd6':
			case '\xd7':
			case '\xd8':
			case '\xd9':
			case '\xda':
			case '\xdb':
			case '\xdc':
			case '\xdd':
			case '\xde':
			case '\xdf':
			case '\xe0':
			case '\xe1':
			case '\xe2':
			case '\xe3':
			case '\xe4':
			case '\xe5':
			case '\xe6':
			case '\xe7':
			case '\xe8':
			case '\xe9':
			case '\xea':
			case '\xeb':
			case '\xec':
			case '\xed':
			case '\xee':
			case '\xef':
			case '\xf0':
			case '\xf1':
			case '\xf2':
			case '\xf3':
			case '\xf4':
			case '\xf5':
			case '\xf6':
			case '\xf7':
			case '\xf8':
			case '\xf9':
			case '\xfa':
			case '\xfb':
			case '\xfc':
			case '\xfd':
			case '\xfe':
			case '\xff': state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_ungetc(lx, c); return lx->z(lx);

		case S2: /* e.g. "\n" */
			lx_ungetc(lx, c); return lx->z = z4, lx->z(lx);
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_EOF;
	case S2: return TOK_EOF;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z4(struct lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, 
		S10, S11, S12, S13, S14, S15, S16, S17, S18, S19, 
		S20, S21, S22, S23, S24, S25, S26, S27
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		switch (state) {
		case S1:
		case S3:
		case S4:
		case S7:
		case S14:
			break;

		default:
			if (lx->push != NULL) {
				if (-1 == lx->push(lx, c)) {
					return TOK_ERROR;
				}
			}
			break;

		}

		switch (state) {
		case S0: /* start */
			switch (c) {
			case '\t':
			case '\n': state = S1; continue;
			case '\r': state = S1; continue;
			case ' ': state = S1; continue;
			case '!': state = S2; continue;
			case '"': state = S3; continue;
			case '#': state = S4; continue;
			case '$': state = S5; continue;
			case '&': state = S6; continue;
			case '\'': state = S7; continue;
			case '(': state = S8; continue;
			case ')': state = S9; continue;
			case '*': state = S10; continue;
			case '+': state = S11; continue;
			case '-': state = S12; continue;
			case '.': state = S13; continue;
			case '\x2f': state = S14; continue;
			case ';': state = S15; continue;
			case '=': state = S16; continue;
			case '?': state = S17; continue;
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
			case 'Z': state = S18; continue;
			case '\\': state = S19; continue;
			case '^': state = S20; continue;
			case '_': state = S18; continue;
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
			case 'z': state = S18; continue;
			case '{': state = S21; continue;
			case '|': state = S22; continue;
			case '}': state = S23; continue;
			case '~': state = S24; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "\t" */
			switch (c) {
			case '\t':
			case '\n': continue;
			case '\r': continue;
			case ' ': continue;
			default:  lx_ungetc(lx, c); return lx->z(lx);
			}

		case S2: /* e.g. "!" */
			lx_ungetc(lx, c); return TOK_BANG;

		case S3: /* e.g. """ */
			lx_ungetc(lx, c); return lx->z = z1, lx->z(lx);

		case S4: /* e.g. "#" */
			lx_ungetc(lx, c); return lx->z = z3, lx->z(lx);

		case S5: /* e.g. "$" */
			switch (c) {
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
			case 'Z': state = S25; continue;
			case '_': state = S25; continue;
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
			case 'z': state = S25; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S6: /* e.g. "&" */
			lx_ungetc(lx, c); return TOK_AND;

		case S7: /* e.g. "\'" */
			lx_ungetc(lx, c); return lx->z = z2, lx->z(lx);

		case S8: /* e.g. "(" */
			lx_ungetc(lx, c); return TOK_LPAREN;

		case S9: /* e.g. ")" */
			lx_ungetc(lx, c); return TOK_RPAREN;

		case S10: /* e.g. "*" */
			lx_ungetc(lx, c); return TOK_STAR;

		case S11: /* e.g. "+" */
			lx_ungetc(lx, c); return TOK_CROSS;

		case S12: /* e.g. "-" */
			switch (c) {
			case '>': state = S26; continue;
			default:  lx_ungetc(lx, c); return TOK_DASH;
			}

		case S13: /* e.g. "." */
			switch (c) {
			case '.': state = S27; continue;
			default:  lx_ungetc(lx, c); return TOK_DOT;
			}

		case S14: /* e.g. "\x2f" */
			lx_ungetc(lx, c); return lx->z = z0, lx->z(lx);

		case S15: /* e.g. ";" */
			lx_ungetc(lx, c); return TOK_SEMI;

		case S16: /* e.g. "=" */
			lx_ungetc(lx, c); return TOK_BIND;

		case S17: /* e.g. "?" */
			lx_ungetc(lx, c); return TOK_QMARK;

		case S18: /* e.g. "a" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
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
			case 'Z': continue;
			case '_': continue;
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
			case 'z': continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S19: /* e.g. "\\" */
			lx_ungetc(lx, c); return TOK_DASH;

		case S20: /* e.g. "^" */
			lx_ungetc(lx, c); return TOK_HAT;

		case S21: /* e.g. "{" */
			lx_ungetc(lx, c); return TOK_OPEN;

		case S22: /* e.g. "|" */
			lx_ungetc(lx, c); return TOK_PIPE;

		case S23: /* e.g. "}" */
			lx_ungetc(lx, c); return TOK_CLOSE;

		case S24: /* e.g. "~" */
			lx_ungetc(lx, c); return TOK_TILDE;

		case S25: /* e.g. "$a" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
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
			case 'Z': continue;
			case '_': continue;
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
			case 'z': continue;
			default:  lx_ungetc(lx, c); return TOK_TOKEN;
			}

		case S26: /* e.g. "->" */
			lx_ungetc(lx, c); return TOK_MAP;

		case S27: /* e.g. ".." */
			lx_ungetc(lx, c); return TOK_TO;
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_EOF;
	case S2: return TOK_BANG;
	case S3: return TOK_EOF;
	case S4: return TOK_EOF;
	case S6: return TOK_AND;
	case S7: return TOK_EOF;
	case S8: return TOK_LPAREN;
	case S9: return TOK_RPAREN;
	case S10: return TOK_STAR;
	case S11: return TOK_CROSS;
	case S12: return TOK_DASH;
	case S13: return TOK_DOT;
	case S14: return TOK_EOF;
	case S15: return TOK_SEMI;
	case S16: return TOK_BIND;
	case S17: return TOK_QMARK;
	case S18: return TOK_IDENT;
	case S19: return TOK_DASH;
	case S20: return TOK_HAT;
	case S21: return TOK_OPEN;
	case S22: return TOK_PIPE;
	case S23: return TOK_CLOSE;
	case S24: return TOK_TILDE;
	case S25: return TOK_TOKEN;
	case S26: return TOK_MAP;
	case S27: return TOK_TO;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

const char *
lx_name(enum lx_token t)
{
	switch (t) {
	case TOK_IDENT: return "IDENT";
	case TOK_TOKEN: return "TOKEN";
	case TOK_AND: return "AND";
	case TOK_PIPE: return "PIPE";
	case TOK_DOT: return "DOT";
	case TOK_DASH: return "DASH";
	case TOK_HAT: return "HAT";
	case TOK_BANG: return "BANG";
	case TOK_TILDE: return "TILDE";
	case TOK_QMARK: return "QMARK";
	case TOK_CROSS: return "CROSS";
	case TOK_STAR: return "STAR";
	case TOK_RPAREN: return "RPAREN";
	case TOK_LPAREN: return "LPAREN";
	case TOK_CLOSE: return "CLOSE";
	case TOK_OPEN: return "OPEN";
	case TOK_MAP: return "MAP";
	case TOK_TO: return "TO";
	case TOK_SEMI: return "SEMI";
	case TOK_BIND: return "BIND";
	case TOK_RE: return "RE";
	case TOK_HEX: return "HEX";
	case TOK_OCT: return "OCT";
	case TOK_ESC: return "ESC";
	case TOK_CHAR: return "CHAR";
	case TOK_STR: return "STR";
	case TOK_EOF:     return "EOF";
	case TOK_ERROR:   return "ERROR";
	case TOK_UNKNOWN: return "UNKNOWN";
	default: return "?";
	}
}

const char *
lx_example(enum lx_token (*z)(struct lx *), enum lx_token t)
{
	assert(z != NULL);

	if (z == z0) {
		switch (t) {
		case TOK_RE: return "\x2f";
		case TOK_CHAR: return "a";
		default: goto error;
		}
	} else
	if (z == z1) {
		switch (t) {
		case TOK_HEX: return "\\xa";
		case TOK_OCT: return "\\0";
		case TOK_ESC: return "\\f";
		case TOK_CHAR: return "a";
		case TOK_STR: return "\"";
		default: goto error;
		}
	} else
	if (z == z2) {
		switch (t) {
		case TOK_CHAR: return "a";
		case TOK_STR: return "\'";
		default: goto error;
		}
	} else
	if (z == z3) {
		switch (t) {
		default: goto error;
		}
	} else
	if (z == z4) {
		switch (t) {
		case TOK_IDENT: return "a";
		case TOK_TOKEN: return "$a";
		case TOK_AND: return "&";
		case TOK_PIPE: return "|";
		case TOK_DOT: return ".";
		case TOK_DASH: return "-";
		case TOK_HAT: return "^";
		case TOK_BANG: return "!";
		case TOK_TILDE: return "~";
		case TOK_QMARK: return "?";
		case TOK_CROSS: return "+";
		case TOK_STAR: return "*";
		case TOK_RPAREN: return ")";
		case TOK_LPAREN: return "(";
		case TOK_CLOSE: return "}";
		case TOK_OPEN: return "{";
		case TOK_MAP: return "->";
		case TOK_TO: return "..";
		case TOK_SEMI: return ";";
		case TOK_BIND: return "=";
		default: goto error;
		}
	}

error:

	errno = EINVAL;
	return NULL;
}

void
lx_init(struct lx *lx)
{
	static const struct lx lx_default;

	assert(lx != NULL);

	*lx = lx_default;

	lx->c = EOF;
	lx->z = z4;

	lx->end.byte = 0;
	lx->end.line = 1;
	lx->end.col  = 1;
}

enum lx_token
lx_next(struct lx *lx)
{
	enum lx_token t;

	assert(lx != NULL);
	assert(lx->z != NULL);

	if (lx->lgetc == NULL) {
		return TOK_EOF;
	}

	t = lx->z(lx);

	if (lx->push != NULL) {
		if (-1 == lx->push(lx, '\0')) {
			return TOK_ERROR;
		}
	}

	return t;
}

