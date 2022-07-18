#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/bool4.gen.cs
#pragma pack(push,1)
	struct bool4
	{
	public:
		static const  bool4	zero;
        union {
            struct { bool x, y, z, w; };
            bool        data[4];
        };


	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        bool4() : x(false), y(false), z(false), w(false) {}
		bool4(bool _x, bool _y, bool _z, bool _w) : x(_x), y(_y), z(_z), w(_w)  {}
        bool4(bool v)                                   {   x = v;      y = v;          z = v;          w = v;          }

        bool4(bool _x, bool _y, const bool2& _zw)       {   x = _x;     y = _y;         z = _zw.x;      w = _zw.y;      }
        bool4(bool _x, const bool2& _yz, bool _w)       {   x = _x;     y = _yz.x;      z = _yz.y;      w = _w;         }
        bool4(bool _x, const bool3& _yzw)               {   x = _x;     y = _yzw.x;     z = _yzw.y;     w = _yzw.z;     }
        bool4(const bool2& _xy, bool _z, bool _w)       {   x = _xy.x;  y = _xy.y;      z = _z;         w = _w;         }
        bool4(const bool2& _xy, const bool2& _zw)       {   x = _xy.x;  y = _xy.y;      z = _zw.x;      w = _zw.y;      }
        bool4(const bool3& _xyz, bool _w)               {   x = _xyz.x; y = _xyz.y;     z = _xyz.z;     w = _w;         }
        bool4(const bool4& _xyzw)                       {   x = _xyzw.x;y = _xyzw.y;    z = _xyzw.z;    w = _xyzw.w;    }

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
        bool4  operator & (const bool4& rhs)    const   { return bool4(this->x & rhs.x,     this->y & rhs.y,    this->z & rhs.z,    this->w & rhs.w); }
        bool4  operator & (bool rhs)            const   { return bool4(this->x & rhs,       this->y & rhs,      this->z & rhs,      this->w & rhs); }
        friend bool4  operator & (bool lhs, const bool4& rhs) { return bool4(lhs & rhs.x, lhs & rhs.y, lhs & rhs.z, lhs & rhs.w); }
        
		// bitwise OR       :   a | b
        bool4  operator | (const bool4& rhs)    const   { return bool4(this->x | rhs.x,     this->y | rhs.y,    this->z | rhs.z,    this->w | rhs.w); }
        bool4  operator | (bool rhs)            const   { return bool4(this->x | rhs,       this->y | rhs,      this->z | rhs,      this->w | rhs); }
        friend bool4  operator | (bool lhs, const bool4& rhs) { return bool4(lhs | rhs.x, lhs | rhs.y, lhs | rhs.z, lhs | rhs.w); }

        // bitwise XOR      :   a ^ b
        bool4  operator ^ (const bool4& rhs)    const   { return bool4(this->x ^ rhs.x,     this->y ^ rhs.y,    this->z ^ rhs.z,    this->w ^ rhs.w); }
        bool4  operator ^ (bool rhs)            const   { return bool4(this->x ^ rhs,       this->y ^ rhs,      this->z ^ rhs,      this->w ^ rhs); }
        friend bool4  operator ^ (bool lhs, const bool4& rhs) { return bool4(lhs ^ rhs.x, lhs ^ rhs.y, lhs ^ rhs.z, lhs ^ rhs.w); }

		// bitwise left shift : a << b
		// bitwise right shift: a >> b

		//=========================================================
		// Logical operators
		//=========================================================
		// negation	        :   not a, !a
        bool4  operator ! () const                  { return bool4(!this->x, !this->y, !this->z, !this->w); }

		// AND	            :   a and b, a && b
		// inclusive OR	    :   a or b,  a || b

		//=========================================================
		// Comparison operators
		//=========================================================
		// equal to         :   a == 
        bool4  operator == (const bool4& rhs)   const   { return bool4(this->x == rhs.x,    this->y == rhs.y,   this->z == rhs.z,   this->w == rhs.w); }
        bool4  operator == (bool rhs)           const   { return bool4(this->x == rhs,      this->y == rhs,     this->z == rhs,     this->w == rhs); }
        friend bool4  operator ==(bool lhs, const bool4& rhs) { return bool4(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z, lhs == rhs.w); }

		// not equal to     :   a != b
        bool4  operator != (const bool4& rhs)   const   { return bool4(this->x != rhs.x,    this->y != rhs.y,   this->z != rhs.z,   this->w != rhs.w); }
        bool4  operator != (bool rhs)           const   { return bool4(this->x != rhs,      this->y != rhs,     this->z != rhs,     this->w != rhs); }
        friend bool4  operator !=(bool lhs, const bool4& rhs) { return bool4(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z, lhs != rhs.w); }

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
			if (index >= 4)
				throw std::exception("index must be between[0...3]");
#endif
			return data[index];
		}

        //=========================================================
		// Getter/Setter
		//=========================================================
        bool4 xxxx() const;
        bool4 xxxy() const;
        bool4 xxxz() const;
        bool4 xxxw() const;
        bool4 xxyx() const;
        bool4 xxyy() const;
        bool4 xxyz() const;
        bool4 xxyw() const;
        bool4 xxzx() const;
        bool4 xxzy() const;
        bool4 xxzz() const;
        bool4 xxzw() const;
        bool4 xxwx() const;
        bool4 xxwy() const;
        bool4 xxwz() const;
        bool4 xxww() const;
        bool4 xyxx() const;
        bool4 xyxy() const;
        bool4 xyxz() const;
        bool4 xyxw() const;
        bool4 xyyx() const;
        bool4 xyyy() const;
        bool4 xyyz() const;
        bool4 xyyw() const;
        bool4 xyzx() const;
        bool4 xyzy() const;
        bool4 xyzz() const;
        bool4 xyzw() const;
        void  xyzw(const bool4& v);
        bool4 xywx() const;
        bool4 xywy() const;
        bool4 xywz() const;
        void  xywz(const bool4 &v);
        bool4 xyww() const;
        bool4 xzxx() const;
        bool4 xzxy() const;
        bool4 xzxz() const;
        bool4 xzxw() const;
        bool4 xzyx() const;
        bool4 xzyy() const;
        bool4 xzyz() const;
        bool4 xzyw() const;
        void  xzyw(const bool4& v);
        bool4 xzzx() const;
        bool4 xzzy() const;
        bool4 xzzz() const;
        bool4 xzzw() const;
        bool4 xzwx() const;
        bool4 xzwy() const;
        void  xzwy(const bool4& v);
        bool4 xzwz() const;
        bool4 xzww() const;
        bool4 xwxx() const;
        bool4 xwxy() const;
        bool4 xwxz() const;
        bool4 xwxw() const;
        bool4 xwyx() const;
        bool4 xwyy() const;
        bool4 xwyz() const;
        void  xwyz(const bool4& v);
        bool4 xwyw() const;
        bool4 xwzx() const;
        bool4 xwzy() const;
        void  xwzy(const bool4& v);
        bool4 xwzz() const;
        bool4 xwzw() const;
        bool4 xwwx() const;
        bool4 xwwy() const;
        bool4 xwwz() const;
        bool4 xwww() const;
        bool4 yxxx() const;
        bool4 yxxy() const;
        bool4 yxxz() const;
        bool4 yxxw() const;
        bool4 yxyx() const;
        bool4 yxyy() const;
        bool4 yxyz() const;
        bool4 yxyw() const;
        bool4 yxzx() const;
        bool4 yxzy() const;
        bool4 yxzz() const;
        bool4 yxzw() const;
        void  yxzw(const bool4& v);
        bool4 yxwx() const;
        bool4 yxwy() const;
        bool4 yxwz() const;
        void  yxwz(const bool4& v);
        bool4 yxww() const;
        bool4 yyxx() const;
        bool4 yyxy() const;
        bool4 yyxz() const;
        bool4 yyxw() const;
        bool4 yyyx() const;
        bool4 yyyy() const;
        bool4 yyyz() const;
        bool4 yyyw() const;
        bool4 yyzx() const;
        bool4 yyzy() const;
        bool4 yyzz() const;
        bool4 yyzw() const;
        bool4 yywx() const;
        bool4 yywy() const;
        bool4 yywz() const;
        bool4 yyww() const;
        bool4 yzxx() const;
        bool4 yzxy() const;
        bool4 yzxz() const;
        bool4 yzxw() const;
        void  yzxw(const bool4& v);
        bool4 yzyx() const;
        bool4 yzyy() const;
        bool4 yzyz() const;
        bool4 yzyw() const;
        bool4 yzzx() const;
        bool4 yzzy() const;
        bool4 yzzz() const;
        bool4 yzzw() const;
        bool4 yzwx() const;
        void  yzwx(const bool4& v);
        bool4 yzwy() const;
        bool4 yzwz() const;
        bool4 yzww() const;
        bool4 ywxx() const;
        bool4 ywxy() const;
        bool4 ywxz() const;
        void  ywxz(const bool4& v);
        bool4 ywxw() const;
        bool4 ywyx() const;
        bool4 ywyy() const;
        bool4 ywyz() const;
        bool4 ywyw() const;
        bool4 ywzx() const;
        void  ywzx(const bool4& v);
        bool4 ywzy() const;
        bool4 ywzz() const;
        bool4 ywzw() const;
        bool4 ywwx() const;
        bool4 ywwy() const;
        bool4 ywwz() const;
        bool4 ywww() const;
        bool4 zxxx() const;
        bool4 zxxy() const;
        bool4 zxxz() const;
        bool4 zxxw() const;
        bool4 zxyx() const;
        bool4 zxyy() const;
        bool4 zxyz() const;
        bool4 zxyw() const;
        void  zxyw(const bool4& v);
        bool4 zxzx() const;
        bool4 zxzy() const;
        bool4 zxzz() const;
        bool4 zxzw() const;
        bool4 zxwx() const;
        bool4 zxwy() const;
        void  zxwy(const bool4& v);
        bool4 zxwz() const;
        bool4 zxww() const;
        bool4 zyxx() const;
        bool4 zyxy() const;
        bool4 zyxz() const;
        bool4 zyxw() const;
        void  zyxw(const bool4& v);
        bool4 zyyx() const;
        bool4 zyyy() const;
        bool4 zyyz() const;
        bool4 zyyw() const;
        bool4 zyzx() const;
        bool4 zyzy() const;
        bool4 zyzz() const;
        bool4 zyzw() const;
        bool4 zywx() const;
        void  zywx(const bool4& v);
        bool4 zywy() const;
        bool4 zywz() const;
        bool4 zyww() const;
        bool4 zzxx() const;
        bool4 zzxy() const;
        bool4 zzxz() const;
        bool4 zzxw() const;
        bool4 zzyx() const;
        bool4 zzyy() const;
        bool4 zzyz() const;
        bool4 zzyw() const;
        bool4 zzzx() const;
        bool4 zzzy() const;
        bool4 zzzz() const;
        bool4 zzzw() const;
        bool4 zzwx() const;
        bool4 zzwy() const;
        bool4 zzwz() const;
        bool4 zzww() const;
        bool4 zwxx() const;
        bool4 zwxy() const;
        void  zwxy(const bool4& v);
        bool4 zwxz() const;
        bool4 zwxw() const;
        bool4 zwyx() const;
        void  zwyx(const bool4& v);
        bool4 zwyy() const;
        bool4 zwyz() const;
        bool4 zwyw() const;
        bool4 zwzx() const;
        bool4 zwzy() const;
        bool4 zwzz() const;
        bool4 zwzw() const;
        bool4 zwwx() const;
        bool4 zwwy() const;
        bool4 zwwz() const;
        bool4 zwww() const;
        bool4 wxxx() const;
        bool4 wxxy() const;
        bool4 wxxz() const;
        bool4 wxxw() const;
        bool4 wxyx() const;
        bool4 wxyy() const;
        bool4 wxyz() const;
        void  wxyz(const bool4& v);
        bool4 wxyw() const;
        bool4 wxzx() const;
        bool4 wxzy() const;
        void  wxzy(const bool4& v);
        bool4 wxzz() const;
        bool4 wxzw() const;
        bool4 wxwx() const;
        bool4 wxwy() const;
        bool4 wxwz() const;
        bool4 wxww() const;
        bool4 wyxx() const;
        bool4 wyxy() const;
        bool4 wyxz() const;
        void  wyxz(const bool4& v);
        bool4 wyxw() const;
        bool4 wyyx() const;
        bool4 wyyy() const;
        bool4 wyyz() const;
        bool4 wyyw() const;
        bool4 wyzx() const;
        void  wyzx(const bool4& v);
        bool4 wyzy() const;
        bool4 wyzz() const;
        bool4 wyzw() const;
        bool4 wywx() const;
        bool4 wywy() const;
        bool4 wywz() const;
        bool4 wyww() const;
        bool4 wzxx() const;
        bool4 wzxy() const;
        void  wzxy(const bool4& v);
        bool4 wzxz() const;
        bool4 wzxw() const;
        bool4 wzyx() const;
        void  wzyx(const bool4& v);
        bool4 wzyy() const;
        bool4 wzyz() const;
        bool4 wzyw() const;
        bool4 wzzx() const;
        bool4 wzzy() const;
        bool4 wzzz() const;
        bool4 wzzw() const;
        bool4 wzwx() const;
        bool4 wzwy() const;
        bool4 wzwz() const;
        bool4 wzww() const;
        bool4 wwxx() const;
        bool4 wwxy() const;
        bool4 wwxz() const;
        bool4 wwxw() const;
        bool4 wwyx() const;
        bool4 wwyy() const;
        bool4 wwyz() const;
        bool4 wwyw() const;
        bool4 wwzx() const;
        bool4 wwzy() const;
        bool4 wwzz() const;
        bool4 wwzw() const;
        bool4 wwwx() const;
        bool4 wwwy() const;
        bool4 wwwz() const;
        bool4 wwww() const;
        bool3 xxx()  const;
        bool3 xxy()  const;
        bool3 xxz()  const;
        bool3 xxw()  const;
        bool3 xyx()  const;
        bool3 xyy()  const;
        bool3 xyz()  const;
        void  xyz(const bool3& v);
        bool3 xyw()  const;
        void  xyw(const bool3& v);
        bool3 xzx()  const;
        bool3 xzy()  const;
        void  xzy(const bool3& v);
        bool3 xzz()  const;
        bool3 xzw()  const;
        void  xzw(const bool3& v);
        bool3 xwx()  const;
        bool3 xwy()  const;
        void  xwy(const bool3& v);
        bool3 xwz()  const;
        void  xwz(const bool3& v);
        bool3 xww()  const;
        bool3 yxx()  const;
        bool3 yxy()  const;
        bool3 yxz()  const;
        void  yxz(const bool3& v);
        bool3 yxw()  const;
        void  yxw(const bool3& v);
        bool3 yyx()  const;
        bool3 yyy()  const;
        bool3 yyz()  const;
        bool3 yyw()  const;
        bool3 yzx()  const;
        void  yzx(const bool3& v);
        bool3 yzy()  const;
        bool3 yzz()  const;
        bool3 yzw()  const;
        void  yzw(const bool3& v);
        bool3 ywx()  const;
        void  ywx(const bool3& v);
        bool3 ywy()  const;
        bool3 ywz()  const;
        void  ywz(const bool3& v);
        bool3 yww()  const;
        bool3 zxx()  const;
        bool3 zxy()  const;
        void  zxy(const bool3& v);
        bool3 zxz()  const;
        bool3 zxw()  const;
        void  zxw(const bool3& v);
        bool3 zyx()  const;
        void  zyx(const bool3& v);
        bool3 zyy()  const;
        bool3 zyz()  const;
        bool3 zyw()  const;
        void  zyw(const bool3& v);
        bool3 zzx()  const;
        bool3 zzy()  const;
        bool3 zzz()  const;
        bool3 zzw()  const;
        bool3 zwx()  const;
        void  zwx(const bool3& v);
        bool3 zwy()  const;
        void  zwy(const bool3& v);
        bool3 zwz()  const;
        bool3 zww()  const;
        bool3 wxx()  const;
        bool3 wxy()  const;
        void  wxy(const bool3& v);
        bool3 wxz()  const;
        void  wxz(const bool3& v);
        bool3 wxw()  const;
        bool3 wyx()  const;
        void  wyx(const bool3& v);
        bool3 wyy()  const;
        bool3 wyz()  const;
        void  wyz(const bool3& v);
        bool3 wyw()  const;
        bool3 wzx()  const;
        void  wzx(const bool3& v);
        bool3 wzy()  const;
        void  wzy(const bool3& v);
        bool3 wzz()  const;
        bool3 wzw()  const;
        bool3 wwx()  const;
        bool3 wwy()  const;
        bool3 wwz()  const;
        bool3 www()  const;
        bool2 xx()   const;
        bool2 xy()   const;
        void  xy(const bool2& v);
        bool2 xz()   const;
        void  xz(const bool2& v);
        bool2 xw()   const;
        void  xw(const bool2& v);
        bool2 yx()   const;
        void  yx(const bool2& v);
        bool2 yy()   const;
        bool2 yz()   const;
        void  yz(const bool2& v);
        bool2 yw()   const;
        void  yw(const bool2& v);
        bool2 zx()   const;
        void  zx(const bool2& v);
        bool2 zy()   const;
        void  zy(const bool2& v);
		bool2 zz()   const;
        bool2 zw()   const;
        void  zw(const bool2& v);
        bool2 wx()   const;
        void  wx(const bool2& v);
        bool2 wy()   const;
        void  wy(const bool2& v);
        bool2 wz()   const;
        void  wz(const bool2& v);
        bool2 ww()   const;
        
		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the bool4 is equal to a given bool4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const bool4& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

        /// <summary>Returns true if the bool4 is equal to a given bool4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is bool4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the bool4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the bool4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("bool4({0}, {1}, {2}, {3})", x, y, z, w);
        }
	};
    __declspec(selectany) const bool4   bool4::zero = bool4(0, 0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-bool4
        //=========================================================
        /// <summary>Returns a uint hash code of a bool4 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const bool4& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a bool4 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const bool4& v);

        /// <summary>Returns the result of specified shuffling of the components from two bool4 vectors into a bool value.</summary>
        /// <param name="left">bool4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool.</param>
        /// <returns>bool result of the shuffle operation.</returns>
        bool shuffle(const bool4& left, const bool4& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two bool4 vectors into a bool2 vector.</summary>
        /// <param name="left">bool4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool2 y component.</param>
        /// <returns>bool2 result of the shuffle operation.</returns>
        bool2 shuffle(const bool4& left, const bool4& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two bool4 vectors into a bool3 vector.</summary>
        /// <param name="left">bool4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting bool3 z component.</param>
        /// <returns>bool3 result of the shuffle operation.</returns>
        bool3 shuffle(const bool4& left, const bool4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two bool4 vectors into a bool4 vector.</summary>
        /// <param name="left">bool4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting bool4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting bool4 w component.</param>
        /// <returns>bool4 result of the shuffle operation.</returns>
        bool4 shuffle(const bool4& left, const bool4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs
