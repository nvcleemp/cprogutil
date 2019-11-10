/*
 * Main developer: Nico Van Cleemput
 *
 * Copyright (C) 2016 Nico Van Cleemput.
 * Licensed under the GNU GPL, read the file LICENSE for details.
 */

#ifndef BITSET_H
#define	BITSET_H

typedef unsigned long long int bitset;

#define BS_ZERO 0ULL
#define BS_ONE 1ULL
#define BS_EMPTY_SET 0ULL
#define BS_CLEAR_SET(s) s = BS_EMPTY_SET
#define BS_SINGLETON(el) (BS_ONE << (el))
#define BS_IS_SINGLETON(s) ((s) && (!((s) & ((s)-1))))
#define BS_HAS_MORE_THAN_ONE_ELEMENT(s) ((s) & ((s)-1))
#define BS_IS_NOT_EMPTY(s) (s)
#define BS_IS_EMPTY(s) (!(s))
#define BS_CONTAINS(s, el) ((s) & BS_SINGLETON(el))
#define BS_CONTAINS_ALL(s, elements) (((s) & (elements)) == (elements))
#define BS_ADD(s, el) ((s) |= BS_SINGLETON(el))
#define BS_ADD_ALL(s, elements) ((s) |= (elements))
#define BS_UNION(s1, s2) ((s1) | (s2))
#define BS_INTERSECTION(s1, s2) ((s1) & (s2))
#define BS_SYMMETRIC_DIFFERENCE(s1, s2) ((s1) ^ (s2))
//these will only work if the element is actually in the set
#define BS_REMOVE(s, el) ((s) ^= BS_SINGLETON(el))
#define BS_REMOVE_ALL(s, elements) ((s) ^= (elements))
#define BS_MINUS(s, el) ((s) ^ BS_SINGLETON(el))
#define BS_MINUS_ALL(s, elements) ((s) ^ (elements))
//the following macros perform an extra step, but will work even if the element is not in the set
#define BS_SAFE_REMOVE(s, el) BS_ADD(s, el); BS_REMOVE(s, el)
#define BS_SAFE_REMOVE_ALL(s, elements) BS_ADD_ALL(s, elements); BS_REMOVE_ALL(s, elements)

//the maximum capacity of a set
#define BS_SET_CAPACITY (sizeof(bitset)*8)

#endif	/* BITSET_H */