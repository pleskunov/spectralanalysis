/* Copyright (c) 2012 Massachusetts Institute of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Originally written by Steven G. Johnson, October 2012
 *
 * Original code is available at: http://ab-initio.mit.edu/Faddeeva
 *
 * Modified by Pavel Pleskunov, February 2025
 * - Used parts of the original code responsible for the computation of the 
 *   Dawson integral (a special case for real x) using the Faddeeva function 
 *   as part of the SpectralAnalysis project. The rest of the original code 
 *   has been removed.
 *
 * This file is a part of the SpectralAnalysis software.
 * SpectralAnalysis Copyright (c) 2025 Pavel Pleskunov
 */

#ifndef CHEBYSHEV_POLY_HPP
#define CHEBYSHEV_POLY_HPP

namespace Chebyshev {
  extern double poly_lookup_table(double y100, double x);
}

#endif // CHEBYSHEV_POLY_HPP
