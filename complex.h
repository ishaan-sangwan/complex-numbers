#ifndef COMPLEX
#define COMPLEX

template <class obj>

class complex{
    public:
        complex() 
            :real(0) imagine(0){}
        complex(const obj & real_part)
            :real(real_part), imagine(0){}
        complex(const obj & real_part, const obj & imaginary_part)
            :real(real_part), imagine(imaginary_part){}

        const double magnitude();
        const double arg();
        const complex conj();

        const complex & operator+=(const complex & rhs);
        const complex & operator-=(const complex & rhs);
        const complex & operator *=(const complex & rhs);
        const complex & operator /=(const complex & rhs);

        complex & operator+(const complex & rhs) const;
        complex & operator-(const complex & rhs)const;
        complex & operator*(const complex & rhs)const;
        complex & operator/(const complex & rhs)const;

        bool operator  == (const complex & rhs)const;
        bool operator  != (const complex & rhs)const;

        const complex & operator-(const complex & rhs) const;

    private:
        obj real;
        obj imagine;
};
#endif
