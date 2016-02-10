
/* MACROS DEFINITIONS */ 

#ifndef _ESSENTIAL_H
#define _ESSENTIAL_H 


/* set bit macro */
#define SBIT(p,n) ((p) |=  (1   << (n)))

/* Clear bit macro */
#define CBIT(p,n) ((p) &= (~(1) << (n)))

/* Toggle bit macro */
#define TBIT(p,n) ((p) ^=  (1   << (n)))

/* Shit 1 macro    */
#define BSHIIFT(n) ( 1 << n ) 

/* is True ? */
#define ISTRUE(p,n)        (( (p) & (1<<(n))) != 0 )

/* is False ? */
#define ISFALSE(p,n)       (( (p) & (1<<(n))) == 0 )




#endif