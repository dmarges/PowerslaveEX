//
// Copyright(C) 2014-2015 Samuel Villarreal
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>

template<class type>
class kexStack
{
public:
    kexStack(void);
    ~kexStack(void);
    
    void                Init(const unsigned int stackSize);
    void                Reset(void);
    void                Empty(void);
    type                *Get(void);
    
    const unsigned int  MaxLength(void) const { return length; }
    const unsigned int  CurrentLength(void) const { return aidx; }
    const unsigned int  StackSize(void) const { return size; }
    
    type                &operator[](unsigned int index);
    const type          &operator[](unsigned int index) const;

protected:
    type                *data;
    unsigned int        length;
    unsigned int        aidx;
    unsigned int        size;
};

//
// kexStack::kexStack
//
template<class type>
kexStack<type>::kexStack(void)
{
    data = NULL;
    length = 0;
    aidx = 0;
    size = 128;
}

//
// kexStack::~kexStack
//
template<class type>
kexStack<type>::~kexStack(void)
{
    Empty();
}

//
// kexStack::Init
//
template<class type>
void kexStack<type>::Init(const unsigned int stackSize)
{
    assert(stackSize != 0);
    
    if(data != NULL)
    {
        delete[] data;
        data = NULL;
    }
    
    size = stackSize;
    data = new type[size];
    length = size;
    aidx = 0;
}

//
// kexStack::Reset
//
template<class type>
void kexStack<type>::Reset(void)
{
    aidx = 0;
}

//
// kexStack::Empty
//
template<class type>
void kexStack<type>::Empty(void)
{
    if(data && length > 0)
    {
        delete[] data;
        data = NULL;
        length = 0;
        aidx = 0;
    }
}

//
// kexStack::Get
//
template<class type>
type *kexStack<type>::Get(void)
{
    assert(size != 0);
    
    if(data == NULL)
    {
        Init(size);
    }
    
    // exceeded max capacity?
    if(aidx == length)
    {
        type *olddata = data;
        type *newdata;
        
        // expand stack
        length += size;
        
        // allocate new array
        newdata = new type[length];
        memcpy(newdata, olddata, aidx * sizeof(type));
        
        data = newdata;
        delete[] olddata;
    }
    
    return &data[aidx++];
}

//
// kexStack::operator[]
//
template <class type>
type &kexStack<type>::operator[](unsigned int index)
{
    assert(index < length);
    return data[index];
}

//
// kexStack::operator[]
//
template <class type>
const type &kexStack<type>::operator[](unsigned int index) const
{
    assert(index < length);
    return data[index];
}

#endif
