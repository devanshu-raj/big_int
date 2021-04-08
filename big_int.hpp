/** big_int - Big Integer implementation in C++
    @ devanshu-raj
**/

#include<iostream>
#include<algorithm>
#include<string>

class big_int {

private:

	/** Private Members **/

	std::string val;
	bool is_negative = false;

	void remove_lead_zeros(std::string &val) {
		int cur = 0, len = val.length();
		while (cur < len) {
			if (val[cur] == '0') {
				cur++;
			}
			else break;
		}
		val = val.substr(cur);
	}

	big_int handle_add(big_int x, big_int y) {
		big_int num1(x.val), num2(y.val), result;
		if (x.is_negative && y.is_negative) {
			result = num1.add(num2);
			result.is_negative = true;
			return result;
		}
		if (x.is_negative) {
			if (num1 > num2) {
				result = num1.subtract(num2);
				result.is_negative = true;
				return result;
			}
			else {
				result = num2.subtract(num1);
				return result;
			}
		}
		if (num1 >= num2) {
			result = num1.subtract(num2);
			return result;
		}
		else {
			result = num2.subtract(num1);
			result.is_negative = true;
			return result;
		}
	}

	big_int handle_subtract(big_int x, big_int y) {
		big_int num1(x.val), num2(y.val), result;
		if (x.is_negative && y.is_negative) {
			result = num2.subtract(num1);
			return result;
		}
		if (x.is_negative) {
			result = num2.add(num1);
			result.is_negative = true;
			return result;
		}
		else {
			result = num1.add(num2);
			return result;
		}
	}

	/** Traditional multiplication algorithm
		Time complexity : O(n²)
	**/

	big_int slow_multiply(big_int num) {
		big_int result;
		std::string res = "0", a = this->val, b = num.val;
		for (int i = a.length() - 1; i >= 0; i--) {
			big_int aux1, aux2;
			std::string temp = b;
			int cur_digit = a[i] - '0';
			int carry = 0;

			for (int j = temp.length() - 1; j >= 0; j--) {
				temp[j] = ((temp[j] - '0') * cur_digit) + carry;

				if (temp[j] > 9) {
					carry = (temp[j] / 10);
					temp[j] -= (carry * 10);
				}
				else
					carry = 0;
				temp[j] += '0';
			}
			if (carry > 0)
				temp.insert(0, 1, (carry + '0'));
			temp.append((a.length() - i - 1), '0');

			aux1.val = res; aux2.val = temp;
			big_int aux3 = aux1.add(aux2);
			res = aux3.val;
		}
		remove_lead_zeros(res);
		result.val = res;
		return result;
	}

	/**
		Karatsuba mutliplication algorithm
		ref :- https://en.wikipedia.org/wiki/Karatsuba_algorithm
	**/

	big_int karatsuba_multiply(big_int num) {
		big_int result;
		if (this->digit_count() < 10 && num.digit_count() < 10) {
			if (this->val.empty()) this->val = "0";
			if (num.val.empty()) num.val = "0";
			long long res = stoll(this->val) * stoll(num.val);
			result.set_value(res);
			return result;
		}

		int min_len = std::min(this->digit_count(), num.digit_count());
		int mid = min_len / 2;

		big_int a, b, c, d;
		a.val = this->val.substr(0, this->digit_count() - mid);
		b.val = this->val.substr(this->digit_count() - mid, this->digit_count());
		c.val = num.val.substr(0, num.digit_count() - mid);
		d.val = num.val.substr(num.digit_count() - mid, num.digit_count());

		big_int first_product, second_product, sum_product;
		first_product = a.karatsuba_multiply(c);
		second_product = b.karatsuba_multiply(d);
		sum_product = (a + b) * (c + d);

		big_int first_part = first_product.multiply_10(mid * 2);
		big_int mid_part = (sum_product - first_product - second_product).multiply_10(mid);

		return first_part + mid_part + second_product;
	}

	/** Returns pair of big_int {quotient, remainder} **/

	std::pair<big_int, big_int> div_mod(big_int num) {
		if (num.is_zero())
			throw std::runtime_error("terminated, cannot divide or modulo by 0");
		if (*this < num) {
			return {big_int(0), big_int(this->val)};
		}
		if (*this == num) {
			return {big_int(1), big_int(0)};
		}
		if (this->fits_in_ll() && num.fits_in_ll()) {
			if (this->val.empty()) this->val = "0";
			long long x = stoll(this->val);
			long long y = stoll(num.val);
			return {big_int(x / y), big_int(x % y)};
		}
		long long count = this->digit_count() - num.digit_count();
		big_int x(this->val), y(num.val);
		big_int temp(1), q(0), ans(1);
		while (count >= 0) {
			q = 0;
			while (x >= (q * y).multiply_10(count))
				++q;
			--q;
			temp = q.multiply_10(count);
			ans += temp;
			x = x - y * temp;
			--count;
		}
		--ans;
		return {ans, x};
	}

public:
	/** Public Members **/


	/** Constructors **/

	big_int() {}

	big_int(int num) : big_int(std::to_string(num)) {}

	big_int(long long num) : big_int(std::to_string(num)) {}

	big_int(std::string num) {
		if (num[0] == '-') this->is_negative = true;
		if (num[0] == '+' || num[0] == '-') num.erase(num.begin());
		remove_lead_zeros(num);
		this->val = num;
	}


	/** I/O methods **/

	void read() {
		std::string val;
		std::cin >> val;
		if (val[0] == '-') is_negative = true;
		if (val[0] == '+' || val[0] == '-') val.erase(val.begin());
		remove_lead_zeros(val);
		this->val = val;
	}

	void set_value(int num) {
		if (num < 0) {
			this->is_negative = true;
			num *= -1;
		}
		else this->is_negative = false;
		this->val = std::to_string(num);
	}

	void set_value(long long num) {
		if (num < 0) {
			this->is_negative = true;
			num *= -1LL;
		}
		else this->is_negative = false;
		this->val = std::to_string(num);
	}

	void set_value(std::string num) {
		if (num[0] == '-') this->is_negative = true;
		else this->is_negative = false;
		if (num[0] == '+' || num[0] == '-') num.erase(num.begin());
		remove_lead_zeros(num);
		this->val = num;
	}

	void print() {
		if (this->is_negative) this->val.insert(this->val.begin(), '-');
		std::cout << (this->val.empty() ? "0" : this->val);
	}

	/** Comparison methods **/

	bool is_greater(big_int other) {
		if (!this->is_negative && other.is_negative) return true;
		if (this->is_negative && !other.is_negative) return false;
		std::string a = this->val;
		std::string b = other.val;
		if (a.length() != b.length()) {
			if (this->is_negative && other.is_negative)
				return (a.length() < b.length());
			return (a.length() > b.length());
		}
		for (int i = 0; i < (int)a.length(); i++) {
			if (a[i] == b[i]) continue;
			if (this->is_negative && other.is_negative)
				return (a[i] < b[i]);
			return (a[i] > b[i]);
		}
		return false;
	}

	bool is_smaller(big_int other) {
		if (this->is_negative && !other.is_negative) return true;
		if (!this->is_negative && other.is_negative) return false;
		std::string a = this->val;
		std::string b = other.val;
		if (a.length() != b.length()) {
			if (this->is_negative && other.is_negative)
				return (a.length() > b.length());
			return (a.length() < b.length());
		}
		for (int i = 0; i < (int)a.length(); i++) {
			if (a[i] == b[i]) continue;
			if (this->is_negative && other.is_negative)
				return (a[i] > b[i]);
			return (a[i] < b[i]);
		}
		return false;
	}

	bool is_equal(big_int other) {
		return ((this->val == other.val) && (this->is_negative == other.is_negative));
	}

	/** Utility methods **/

	bool is_zero() {
		if (this->val == "0" || this->val.empty()) return true;
		return false;
	}

	bool fits_in_ll() {
		big_int ll_max("9223372036854775807");
		big_int ll_min("-9223372036854775808");
		return (*this <= ll_max && *this >= ll_min);
	}

	int digit_count() {
		if (this->val.empty()) return 1;
		return this->val.length();
	}

	big_int absolute() {
		big_int result(this->val);
		result.is_negative = false;
		return result;
	}

	big_int multiply_10(int count = 1) {
		big_int result = *this;
		for (int i = 0; i < count; i++) {
			result.val.push_back('0');
		}
		return result;
	}

	big_int divide_10(int count = 1) {
		if (count >= this->digit_count())
			return big_int(0);
		big_int result = *this;
		for (int i = 0; i < count; i++) {
			result.val.pop_back();
		}
		return result;
	}

	/** Arithmetic operations **/

	big_int add(big_int num) {
		big_int result;
		if ((this->is_negative) || (num.is_negative)) {
			result = handle_add(*this, num);
			return result;
		}
		std::string a = this->val;
		std::string b = num.val;
		int cur_a = a.length() - 1, cur_b = b.length() - 1;
		int carry = 0;
		while (cur_a >= 0 || cur_b >= 0 || carry) {
			int cur_sum = 0;
			if (cur_a >= 0) cur_sum += (a[cur_a] - '0'), cur_a--;
			if (cur_b >= 0) cur_sum += (b[cur_b] - '0'), cur_b--;
			cur_sum += carry;
			result.val += ((cur_sum % 10) + '0');
			carry = (cur_sum / 10);
		}
		reverse(result.val.begin(), result.val.end());
		return result;
	}

	big_int subtract(big_int num) {
		big_int result;
		if ((this->is_negative) || (num.is_negative)) {
			result = handle_subtract(*this, num);
			return result;
		}
		if (this->is_smaller(num)) {
			result = num.subtract(*this);
			result.is_negative = true;
			return result;
		}
		std::string a = this->val;
		std::string b = num.val;
		int cur_a = a.length() - 1, cur_b = b.length() - 1;
		while (cur_a >= 0 && cur_b >= 0) {
			if (a[cur_a] >= b[cur_b]) {
				result.val += (((a[cur_a] - '0') - (b[cur_b] - '0')) + '0');
				cur_a--, cur_b--;
				continue;
			}
			int temp = cur_a;
			while (temp--) {
				if (a[temp] == '0') a[temp] = '9';
				else {
					a[temp]--;
					break;
				}
			}
			int y = (a[cur_a] - '0') + 10;
			result.val += ((y - (b[cur_b] - '0')) + '0');
			cur_a--, cur_b--;
		}
		while (cur_a >= 0) result.val += a[cur_a--];
		reverse(result.val.begin(), result.val.end());
		remove_lead_zeros(result.val);
		return result;
	}

	big_int multiply(big_int num) {
		big_int result;
		if (this->is_zero() || num.is_zero()) return result;
		if (this->is_negative || num.is_negative) result.is_negative = true;
		if (this->is_negative && num.is_negative) result.is_negative = false;
		if (num.val == "1") {
			result.val = this->val;
			return result;
		}
		if (this->val == "1") {
			result.val = num.val;
			return result;
		}
		int this_sz = this->digit_count();
		int num_sz = num.digit_count();
		if (abs(this_sz - num_sz) > 8) {
			big_int res = this->slow_multiply(num);
			result.val = res.val;
			return result;
		}
		big_int res = this->karatsuba_multiply(num);
		result.val = res.val;
		return result;
	}

	big_int divide(big_int num) {
		big_int result;
		if (this->is_negative || num.is_negative) result.is_negative = true;
		if (this->is_negative && num.is_negative) result.is_negative = false;

		std::pair<big_int, big_int> qr = this->div_mod(num);
		result.val = qr.first.val;
		if (result.is_zero()) result.is_negative = false;
		return result;
	}

	/** WARNING : The "modulo" method will not work for negative large integers **/

	big_int modulo(big_int num) {
		big_int result;
		if (this->is_negative) result.is_negative = true;

		std::pair<big_int, big_int> qr = this->div_mod(num);
		result.val = qr.second.val;
		if (result.is_zero()) result.is_negative = false;
		return result;
	}

	/** Arithmetic operators overloading **/

	big_int operator + (big_int num) {
		return this->add(num);
	}

	big_int operator - (big_int num) {
		return this->subtract(num);
	}

	big_int operator * (big_int num) {
		return this->multiply(num);
	}

	big_int operator / (big_int num) {
		return this->divide(num);
	}

	big_int operator % (big_int num) {
		return this->modulo(num);
	}

	/** Assignment operators **/

	big_int& operator = (int num) {
		this->set_value(num);
		return *this;
	}

	big_int& operator = (long long num) {
		this->set_value(num);
		return *this;
	}

	big_int& operator = (std::string num) {
		this->set_value(num);
		return *this;
	}

	big_int& operator += (big_int num) {
		*this = *this + num;
		return *this;
	}

	big_int& operator -= (big_int num) {
		*this = *this - num;
		return *this;
	}

	big_int& operator *= (big_int num) {
		*this = *this * num;
		return *this;
	}

	big_int& operator /= (big_int num) {
		*this = *this / num;
		return *this;
	}

	big_int& operator %= (big_int num) {
		*this = *this % num;
		return *this;
	}

	/** Unary operators **/

	big_int operator ++(int) {
		big_int result = *this, one(1);
		*this += one;
		return result;
	}

	big_int operator --(int) {
		big_int result = *this, one(1);
		*this -= one;
		return result;
	}

	big_int& operator ++ () {
		big_int one(1);
		*this += one;
		return *this;
	}

	big_int& operator -- () {
		big_int one(1);
		*this -= one;
		return *this;
	}

	/** I/O stream operators **/

	friend std::ostream& operator << (std::ostream&, big_int);
	friend std::istream& operator >> (std::istream&, big_int&);

	/** Relational operators **/

	friend bool operator < (big_int, big_int);
	friend bool operator > (big_int, big_int);
	friend bool operator == (big_int, big_int);
	friend bool operator >= (big_int, big_int);
	friend bool operator <= (big_int, big_int);
	friend bool operator != (big_int, big_int);

};

/** Friend functions **/

std::istream& operator >> (std::istream &in, big_int& num) {
	num.read();
	return in;
}

std::ostream& operator << (std::ostream &out, big_int num) {
	num.print();
	return out;
}

bool operator < (big_int num1, big_int num2) {
	return num1.is_smaller(num2);
}

bool operator > (big_int num1, big_int num2) {
	return num1.is_greater(num2);
}

bool operator == (big_int num1, big_int num2) {
	return num1.is_equal(num2);
}

bool operator >= (big_int num1, big_int num2) {
	return ((num1 > num2) || (num1 == num2));
}

bool operator <= (big_int num1, big_int num2) {
	return ((num1 < num2) || (num1 == num2));
}

bool operator != (big_int num1, big_int num2) {
	return !(num1 == num2);
}
