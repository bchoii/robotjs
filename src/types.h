#pragma once
#ifndef TYPES_H
#define TYPES_H

#include "os.h"
#include "inline_keywords.h" /* For H_INLINE */
#include <stddef.h>

/* Some generic, cross-platform types. */

struct _MMPoint {
	Maybe<int32_t> x;
	Maybe<int32_t> y;
};

typedef struct _MMPoint MMPoint;

struct _MMSize {
	Maybe<int32_t> width;
	Maybe<int32_t> height;
};

typedef struct _MMSize MMSize;

struct _MMRect {
	MMPoint origin;
	MMSize size;
};

typedef struct _MMRect MMRect;

H_INLINE MMPoint MMPointMake(Maybe<int32_t> x, Maybe<int32_t> y)
{
	MMPoint point;
	point.x = x;
	point.y = y;
	return point;
}

H_INLINE MMSize MMSizeMake(Maybe<int32_t> width, Maybe<int32_t> height)
{
	MMSize size;
	size.width = width;
	size.height = height;
	return size;
}

H_INLINE MMRect MMRectMake(Maybe<int32_t> x, Maybe<int32_t> y, Maybe<int32_t> width, Maybe<int32_t> height)
{
	MMRect rect;
	rect.origin = MMPointMake(x, y);
	rect.size = MMSizeMake(width, height);
	return rect;
}

#define MMPointZero MMPointMake(0, 0)

#if defined(IS_MACOSX)

#define CGPointFromMMPoint(p) CGPointMake((CGFloat)(p).x, (CGFloat)(p).y)
#define MMPointFromCGPoint(p) MMPointMake((Maybe<int32_t>)(p).x, (Maybe<int32_t>)(p).y)

#elif defined(IS_WINDOWS)

#define MMPointFromPOINT(p) MMPointMake((Maybe<int32_t>)p.x, (Maybe<int32_t>)p.y)

#endif

#endif /* TYPES_H */
