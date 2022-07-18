#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/bool3.gen.cs
#pragma pack(push,1)
	struct bool3
	{
	public:
		static const  bool3	zero;
        union {
            struct { bool x, y, z; };
            bool        data[3];
        };


	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        bool3() : x(false), y(false), z(false)  {}
		bool3(bool _x, bool _y, bool _z) : x(_x), y(_y), z(_z)  {}

        bool3(bool _x, const bool2& _yz)            {   x = _x;     y = _yz.x;  z = _yz.y;      }
        bool3(const bool2& _xy, bool _z)            {   x = _xy.x;  y = _xy.y;  z = _z;         }
        bool3(const bool3& _xyz)                    {   x = _xyz.x; y = _xyz.y; z = _xyz.z;     }
        bool3(bool v)                               {   x = v;      y = v;      z = v;          }


		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		// addition assignment	            a += b	
		// subtraction assignment	        a -= b	
		// multiplication assignment	    a *= b	
		// division assignment	            a /= b	
		// modulo assignment	            a %= b	

		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
		// pre - decrement  : 	--a		T&
		// post-increment   : 	a++
		// post-decrement   :	a--

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		// unary minus      :   -a
		// addition         :   a + b
		// subtraction      :   a - b
		// multiplication   :   a * b
		// division         :   a / b
		// modulo           :   a % b

		// bitwise NOT      :   ~a
		// bitwise AND      :   a & b
		bool3  operator & (const bool3& rhs)const   { return bool3(this->x & rhs.x,     this->y & rhs.y,    this->z & rhs.z); }
		bool3  operator & (bool rhs)        const   { return bool3(this->x & rhs,       this->y & rhs,      this->z & rhs); }
        friend bool3 operator & (bool lhs, const bool3& rhs) { return bool3(lhs & rhs.x, lhs & rhs.y, lhs & rhs.z); }

		// bitwise OR       :   a | b
		bool3  operator | (const bool3& rhs)const   { return bool3(this->x | rhs.x,     this->y | rhs.y,    this->z | rhs.z); }
		bool3  operator | (bool rhs)        const   { return bool3(this->x | rhs,       this->y | rhs,      this->z | rhs); }
        friend bool3 operator | (bool lhs, const bool3& rhs) { return bool3(lhs | rhs.x, lhs | rhs.y, lhs | rhs.z); }

		// bitwise XOR      :   a ^ b
		bool3  operator ^ (const bool3& rhs)const   { return bool3(this->x ^ rhs.x,     this->y ^ rhs.y,    this->z ^ rhs.z); }
		bool3  operator ^ (bool rhs)        const   { return bool3(this->x ^ rhs,       this->y ^ rhs,      this->z ^ rhs); }
        friend bool3 operator ^ (bool lhs, const bool3& rhs) { return bool3(lhs ^ rhs.x, lhs ^ rhs.y, lhs ^ rhs.z); }

		// bitwise left shift : a << b
		// bitwise right shift: a >> b

		//=========================================================
		// Logical operators
		//=========================================================
		// negation	        :   not a, !a
        bool3  operator ! () const                  { return bool3(!this->x, !this->y, !this->z); }
		// AND	            :   a and b, a && b
		// inclusive OR	    :   a or b,  a || b

		//=========================================================
		// Comparison operators
		//=========================================================
		// equal to         :   a == 
		bool3  operator ==(const bool3& rhs)const   { return bool3(this->x == rhs.x,    this->y == rhs.y,   this->z == rhs.z); }
		bool3  operator ==(bool rhs)        const   { return bool3(this->x == rhs,      this->y == rhs,     this->z == rhs); }
        friend bool3 operator ==(bool lhs, const bool3& rhs) { return bool3(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z); }

		// not equal to     :   a != b
		bool3  operator !=(const bool3& rhs)const   { return bool3(this->x != rhs.x,    this->y != rhs.y,   this->z != rhs.z); }
		bool3  operator !=(bool rhs)        const   { return bool3(this->x != rhs,      this->y != rhs,     this->z != rhs); }
        friend bool3 operator !=(bool lhs, const bool3& rhs) { return bool3(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z); }

		// less than        :   a < b
		// greater than     :   a > b
		// less than or equal to    : a <= b	
		// greater than or equal to : a >= b

        //=========================================================
        // Conversion operators
        //=========================================================


        //=========================================================
        // member access
        //=========================================================
        /// <summary>Returns the bool element at a specified index.</summary>
        bool operator[] (int index)
        {
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
			if (index >= 3)
				throw std::exception("index must be between[0...2]");
#endif
			return data[index];
        }

        //=========================================================
        // Getter/Setter
        //=========================================================
        bool4 xxxx() const;
        bool4 xxxy() const;
        bool4 xxxz() const;
        bool4 xxyx() const;
        bool4 xxyy() const;
        bool4 xxyz() const;
        bool4 xxzx() const;
        bool4 xxzy() const;
        bool4 xxzz() const;
        bool4 xyxx() const;
        bool4 xyxy() const;
        bool4 xyxz() const;
        bool4 xyyx() const;
        bool4 xyyy() const;
        bool4 xyyz() const;
        bool4 xyzx() const;
        bool4 xyzy() const;
        bool4 xyzz() const;
        bool4 xzxx() const;
        bool4 xzxy() const;
        bool4 xzxz() const;
        bool4 xzyx() const;
        bool4 xzyy() const;
        bool4 xzyz() const;
        bool4 xzzx() const;
        bool4 xzzy() const;
        bool4 xzzz() const;
        bool4 yxxx() const;
        bool4 yxxy() const;
        bool4 yxxz() const;
        bool4 yxyx() const;
        bool4 yxyy() const;
        bool4 yxyz() const;
        bool4 yxzx() const;
        bool4 yxzy() const;
        bool4 yxzz() const;
        bool4 yyxx() const;
        bool4 yyxy() const;
        bool4 yyxz() const;
        bool4 yyyx() const;
        bool4 yyyy() const;
        bool4 yyyz() const;
        bool4 yyzx() const;
        bool4 yyzy() const;
        bool4 yyzz() const;
        bool4 yzxx() const;
        bool4 yzxy() const;
        bool4 yzxz() const;
        bool4 yzyx() const;
        bool4 yzyy() const;
        bool4 yzyz() const;
        bool4 yzzx() const;
        bool4 yzzy() const;
        bool4 yzzz() const;
        bool4 zxxx() const;
        bool4 zxxy() const;
        bool4 zxxz() const;
        bool4 zxyx() const;
        bool4 zxyy() const;
        bool4 zxyz() const;
        bool4 zxzx() const;
        bool4 zxzy() const;
        bool4 zxzz() const;
        bool4 zyxx() const;
        bool4 zyxy() const;
        bool4 zyxz() const;
        bool4 zyyx() const;
        bool4 zyyy() const;
        bool4 zyyz() const;
        bool4 zyzx() const;
        bool4 zyzy() const;
        bool4 zyzz() const;
        bool4 zzxx() const;
        bool4 zzxy() const;
        bool4 zzxz() const;
        bool4 zzyx() const;
        bool4 zzyy() const;
        bool4 zzyz() const;
        bool4 zzzx() const;
        bool4 zzzy() const;
        bool4 zzzz() const;
        bool3 xxx()  const;
        bool3 xxy()  const;
        bool3 xxz()  const;
        bool3 xyx()  const;
        bool3 xyy()  const;
        bool3 xyz()  const;
        void  xyz(const bool3& v);
        bool3 xzx()  const;
        bool3 xzy()  const;
        void  xzy(const bool3& v);
        bool3 xzz()  const;
        bool3 yxx()  const;
        bool3 yxy()  const;
        bool3 yxz()  const;
        void  yxz(const bool3& v);
        bool3 yyx()  const;
        bool3 yyy()  const;
        bool3 yyz()  const;
        bool3 yzx()  const;
        void  yzx(const bool3& v);
        bool3 yzy()  const;
        bool3 yzz()  const;
        bool3 zxx()  const;
        bool3 zxy()  const;
        void  zxy(const bool3& v);
        bool3 zxz()  const;
        bool3 zyx()  const;
        void  zyx(const bool3& v);
        bool3 zyy()  const;
        bool3 zyz()  const;
        bool3 zzx()  const;
        bool3 zzy()  const;
        bool3 zzz()  const;
        bool2 xx()   const;
        bool2 xy()   const;
        void  xy(const bool2& v);
        bool2 xz()   const;
        void  xz(const bool2& v);
        bool2 yx()   const;
        void  yx(const bool2& v);
        bool2 yy()   const;
        bool2 yz()   const;
        void  yz(const bool2& v);
        bool2 zx()   const;
        void  zx(const bool2& v);
        bool2 zy()   const;
        void  zy(const bool2& v);
        bool2 zz()   const;

		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the bool3 is equal to a given bool3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const bool3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

        /// <summary>Returns true if the bool3 is equal to a given bool3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is bool3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the bool3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the bool3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("bool3({0}, {1}, {2})", x, y, z);
        }
	};
    __declspec(selectany) const bool3   bool3::zero = bool3(0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-bool3
        //=========================================================
        /// <summary>Returns a uint hash code of a bool3 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const bool3& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a bool3 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const bool3& v);

        /// <summary>Returns the result of specified shuffling of the components from two bool3 vectors into a bool value.</summary>
        /// <param name="left">bool3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool.</param>
        /// <returns>bool result of the shuffle operation.</returns>
        bool shuffle(const bool3& left, const bool3& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two bool3 vectors into a bool2 vector.</summary>
        /// <param name="left">bool3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool2 y component.</param>
        /// <returns>bool2 result of the shuffle operation.</returns>
        bool2 shuffle(const bool3& left, const bool3& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two bool3 vectors into a bool3 vector.</summary>
        /// <param name="left">bool3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting bool3 z component.</param>
        /// <returns>bool3 result of the shuffle operation.</returns>
        bool3 shuffle(const bool3& left, const bool3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two bool3 vectors into a bool4 vector.</summary>
        /// <param name="left">bool3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting bool4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting bool4 w component.</param>
        /// <returns>bool4 result of the shuffle operation.</returns>
        bool4 shuffle(const bool3& left, const bool3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs
