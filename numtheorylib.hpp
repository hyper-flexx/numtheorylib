#pragma once

/*
	MIT License
	Copyright (c) 2021 marchie
	https://github.com/hyper-flexx/numtheorylib

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

/* Copy the code below to your source file */
namespace MNumTheory {
	namespace numbertheory {
		template <class T, bool multidivisor> class divisor {
		protected:
			T value, Amount = 0;
		public:
			const bool multi = multidivisor;
			divisor(T _value) : value(_value){}
			operator T& () { return value; }
			T& amount() { if (!multidivisor) throw; return Amount; }
		};
		template <class T, bool recursive_compute> class templater {
		protected:
			static void swap(T& a, T& b) { T _a = a; a = b; b = _a; }
		public:
			T greatest_common_divisor(T a, T b) {
				if (recursive_compute) {
					if (a % b == 0) return b;
					else if (b % a == 0) return a;
					else if (a > b) return greatest_common_divisor(a % b, b);
					else return greatest_common_divisor(a, b % a);
				}
				else {
					if (a < b) swap(a, b);
					while (a % b != 0) { a = a % b; swap(a, b); }
					return b;
				}
			}
			T least_common_multiple(T a, T b) {
				return (a * b) / greatest_common_divisor(a, b);
			}
			template <class divisor_t>
			divisor_t iterative_divide(T& n, divisor_t div = divisor_t(2)) {
				if (n == 1) return divisor_t(1);
				while (n % div != 0) {
					if (div == 2) div++;
					else div += 2;
				}
				while (n % div == 0) {
					n /= div;
					if (!div.multi) break;
					else div.amount()++;
				}
				return div;
			}
		};
	}
	template <class T = unsigned int, class templater = numbertheory::templater<T, true>, class divisor = numbertheory::divisor<T, false>>
	class solver {
	protected:
		templater Templater;
	public:
		struct pair{ 
			T first, second;
			pair(T _first, T _second) : first(_first), second(_second){}
		};
		T operator[](pair p) { return Templater.least_common_multiple(p.first, p.second); }
		T operator()(T a, T b) { return Templater.greatest_common_divisor(a, b); }
		templater& get_templater() { return Templater; }
	};
}