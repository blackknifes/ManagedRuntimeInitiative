/*
 * Copyright 1999-2004 Sun Microsystems, Inc.  All Rights Reserved.
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


#include "osThread.hpp"

#include <os/thread.h>

 // ***************************************************************
 // Platform dependent initialization and cleanup
 // ***************************************************************

void OSThread::pd_initialize() {
  set_thread_id(0);
  set_pthread_id(0);
}

// Note from win32 code: this is not well encapsulated; creation and deletion of the
// interrupt_semaphore are done in os_linux.cpp, create_thread and
// free_thread. Should follow pattern of Windows/Linux/Solaris code here.
void OSThread::pd_destroy()
{
  // Now the OSThread is no longer accessible, the thread handle may be deallocated
  // (doing it any other time we have a race).
  pthread_t thread_handle = pthread_id();
  pthread_t self          = pthread_self();
  if (self != thread_handle) 
  {
    // TODO: Do we have to deallocate pthread threads after they've exited?
    //thread_deallocate(thread_handle);

    set_thread_id(0);
    set_pthread_id(0);
  }
}
