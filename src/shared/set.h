/***
  This file is part of eudev, forked from systemd.

  Copyright 2010 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#pragma once

/* Pretty straightforward set implementation. Internally based on the
 * hashmap. That means that as a minor optimization a NULL set
 * object will be treated as empty set for all read
 * operations. That way it is not necessary to instantiate an object
 * for each set use. */

#include "hashmap.h"
#include "util.h"

typedef struct Set Set;

Set *set_new(const struct hash_ops *hash_ops);
void set_free(Set* s);

int set_put(Set *s, void *value);
void *set_get(Set *s, void *value);
bool set_contains(Set *s, void *value);

int set_reserve(Set *s, unsigned entries_add);

void *set_iterate(Set *s, Iterator *i);

DEFINE_TRIVIAL_CLEANUP_FUNC(Set*, set_free);
#define _cleanup_set_free_ _cleanup_(set_freep)
