/*
 * Copyright 2003 Sun Microsystems, Inc.  All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa Clara,
 * CA 95054 USA or visit www.sun.com if you need additional information or
 * have any questions.
 *  
 */
// This file is a derivative work resulting from (and including) modifications
// made by Azul Systems, Inc.  The date of such changes is 2010.
// Copyright 2010 Azul Systems, Inc.  All Rights Reserved.
//
// Please contact Azul Systems, Inc., 1600 Plymouth Street, Mountain View, 
// CA 94043 USA, or visit www.azulsystems.com if you need additional information 
// or have any questions.
#ifndef ASPSOLDGEN_HPP
#define ASPSOLDGEN_HPP

#include "psOldGen.hpp"

class ASPSOldGen : public PSOldGen {
  friend class VMStructs;
  size_t _gen_size_limit;  // Largest size the generation's reserved size
			   // can grow.
 public:
  ASPSOldGen(size_t initial_byte_size,
             size_t minimum_byte_size, 
	     size_t byte_size_limit,
             const char* gen_name, int level);
  ASPSOldGen(PSVirtualSpace* vs, 
	     size_t initial_byte_size,
             size_t minimum_byte_size, 
	     size_t byte_size_limit,
             const char* gen_name, int level);
  size_t gen_size_limit() 		{ return _gen_size_limit; }
  size_t max_gen_size() 		{ return _reserved.byte_size(); }
  void set_gen_size_limit(size_t v) 	{ _gen_size_limit = v; }

  // After a shrink or expand reset the generation
  void reset_after_change();

  // Return number of bytes that the virtual space in the generation is willing
  // to expand or contract.  The results from these methods should feed into the
  // decisions about adjusting the virtual space.
  size_t available_for_expansion();
  size_t available_for_contraction();

  // Accessors
  void set_reserved(MemRegion v) { _reserved = v; }

  // Debugging support
  virtual const char* short_name() const { return "ASPSOldGen"; }
};

#endif // ASPSOLDGEN_HPP

