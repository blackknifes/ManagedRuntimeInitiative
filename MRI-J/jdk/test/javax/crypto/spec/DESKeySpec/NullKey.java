/*
 * Copyright 2004-2007 Sun Microsystems, Inc.  All Rights Reserved.
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
 */

/*
 * @test
 * @bug 4959570
 * @summary DESKeySpec constructors and static methods should throw exception
 *   if the key parameter is null.
 * @author Sean Mullan
 */
import java.security.InvalidKeyException;
import javax.crypto.spec.DESKeySpec;

public class NullKey {

    public static void main(String[] args) throws Exception {

        try {
            DESKeySpec desSpec = new DESKeySpec(null);
            throw new Exception("expected NullPointerException");
        } catch (NullPointerException npe) {}

        try {
            DESKeySpec desSpec = new DESKeySpec(null, 0);
            throw new Exception("expected NullPointerException");
        } catch (NullPointerException npe) {}

        try {
            boolean parityAdjusted = DESKeySpec.isParityAdjusted(null, 0);
            throw new Exception("expected InvalidKeyException");
        } catch (InvalidKeyException ike) {}

        try {
            boolean weak = DESKeySpec.isWeak(null, 0);
            throw new Exception("expected InvalidKeyException");
        } catch (InvalidKeyException ike) {}

    }
}
