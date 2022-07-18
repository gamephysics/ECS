#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/bool2.gen.cs
#pragma pack(push,1)
    struct bool2
    {
    public:
        static const  bool2	zero;
        union {
            struct { bool x, y; };
            bool        data[2];
        };

    public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        bool2() : x(false), y(false) {}
        bool2(bool _x, bool _y) : x(_x), y(_y) {}

        bool2(bool v) : x(v), y(v) {}

        bool2(const bool2& v) : x(v.x), y(v.y) {}
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
        bool2  operator & (const bool2& rhs)const { return bool2(this->x & rhs.x, this->y & rhs.y); }
        bool2  operator & (bool rhs)        const { return bool2(this->x & rhs, this->y & rhs); }
        friend bool2  operator & (bool lhs, const bool2& rhs) { return bool2(lhs & rhs.x, lhs & rhs.y); }

        // bitwise OR       :   a | b
        bool2  operator | (const bool2& rhs)const { return bool2(this->x | rhs.x, this->y | rhs.y); }
        bool2  operator | (bool rhs)        const { return bool2(this->x | rhs, this->y | rhs); }
        friend bool2  operator | (bool lhs, const bool2& rhs) { return bool2(lhs | rhs.x, lhs | rhs.y); }

        // bitwise XOR      :   a ^ b
        bool2  operator ^ (const bool2& rhs)const { return bool2(this->x ^ rhs.x, this->y ^ rhs.y); }
        bool2  operator ^ (bool rhs)        const { return bool2(this->x ^ rhs, this->y ^ rhs); }
        friend bool2  operator ^ (bool lhs, const bool2& rhs) { return bool2(lhs ^ rhs.x, lhs ^ rhs.y); }

        // bitwise left shift : a << b
        // bitwise right shift: a >> b

        //=========================================================
        // Logical operators
        //=========================================================
        // negation	        :   not a, !a
        bool2  operator ! () const { return bool2(!this->x, !this->y); }
        // AND	            :   a and b, a && b
        // inclusive OR	    :   a or b,  a || b

        //=========================================================
        // Comparison operators
        //=========================================================
        // equal to         :   a == 
        bool2  operator ==(const bool2& rhs)const { return bool2(this->x == rhs.x, this->y == rhs.y); }
        bool2  operator ==(bool rhs)        const { return bool2(this->x == rhs, this->y == rhs); }
        friend bool2  operator ==(bool lhs, const bool2& rhs) { return bool2(lhs == rhs.x, lhs == rhs.y); }

        // not equal to     :   a != b
        bool2  operator !=(const bool2& rhs)const { return bool2(this->x != rhs.x, this->y != rhs.y); }
        bool2  operator !=(bool rhs)		const { return bool2(this->x != rhs, this->y != rhs); }
        friend bool2  operator !=(bool lhs, const bool2& rhs) { return bool2(lhs != rhs.x, lhs != rhs.y); }

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
        bool& operator[] (int index)
        {
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
            if (index >= 2)
                throw std::exception("index must be between[0...1]");
#endif
            return data[index];
        }

        //=========================================================
        // Getter/Setter
        //=========================================================
        /// <summary>Swizzles the vector.</summary>
        bool4 xxxx() const;
        bool4 xxxy() const;
        bool4 xxyx() const;
        bool4 xxyy() const;
        bool4 xyxx() const;
        bool4 xyxy() const;
        bool4 xyyx() const;
        bool4 xyyy() const;
        bool4 yxxx() const;
        bool4 yxxy() const;
        bool4 yxyx() const;
        bool4 yxyy() const;
        bool4 yyxx() const;
        bool4 yyxy() const;
        bool4 yyyx() const;
        bool4 yyyy() const;
        bool3 xxx()  const;
        bool3 xxy()  const;
        bool3 xyx()  const;
        bool3 xyy()  const;
        bool3 yxx()  const;
        bool3 yxy()  const;
        bool3 yyx()  const;
        bool3 yyy()  const;
        bool2 xx()   const;
        bool2 xy()   const;
        void  xy(const bool2& v);
        bool2 yx()   const;
        void  yx(const bool2& v);
        bool2 yy()   const;

        //=========================================================
        // METHOD 
        //=========================================================
        /// <summary>Returns true if the bool2 is equal to a given bool2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const bool2& rhs) const { return x == rhs.x && y == rhs.y; }

        /// <summary>Returns true if the bool2 is equal to a given bool2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //bool Equals(object o)			{ return o is bool2 converted && Equals(converted); }

        /// <summary>Returns a hash code for the bool2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode()				{ return (int)math::hash(*this); }

        /// <summary>Returns a string representation of the bool2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("bool2({0}, {1})", x, y);
        }

    };
    __declspec(selectany) const bool2   bool2::zero = bool2(0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-bool2
        //=========================================================
        /// <summary>Returns a uint hash code of a bool2 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const bool2& v);

        /// <summary>
        /// Returns a uint2 vector hash code of a bool2 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const bool2& v);

        /// <summary>Returns the result of specified shuffling of the components from two bool2 vectors into a bool value.</summary>
        /// <param name="left">bool2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool.</param>
        /// <returns>bool result of the shuffle operation.</returns>
        bool shuffle(const bool2& left, const bool2& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two bool2 vectors into a bool2 vector.</summary>
        /// <param name="left">bool2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool2 y component.</param>
        /// <returns>bool2 result of the shuffle operation.</returns>
        bool2 shuffle(const bool2& left, const bool2& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two bool2 vectors into a bool3 vector.</summary>
        /// <param name="left">bool2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting bool3 z component.</param>
        /// <returns>bool3 result of the shuffle operation.</returns>
        bool3 shuffle(const bool2& left, const bool2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two bool2 vectors into a bool4 vector.</summary>
        /// <param name="left">bool2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">bool2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting bool4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting bool4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting bool4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting bool4 w component.</param>
        /// <returns>bool4 result of the shuffle operation.</returns>
        bool4 shuffle(const bool2& left, const bool2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs
