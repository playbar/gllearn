//
// Created by hou guoli on 2019/5/7.
//

#ifndef IMAGELIB_CREFPTR_H
#define IMAGELIB_CREFPTR_H

#include <stdlib.h>             /* NULL */

template <typename T>
class CRefPtr
{
public:
    CRefPtr<T>();
    CRefPtr<T>(T * ptr);
    CRefPtr<T>(const CRefPtr<T> & orig);
    CRefPtr<T> & operator=(const CRefPtr<T> & orig);
    CRefPtr<T> & operator=(T * ptr);
    ~CRefPtr<T>();
    T & operator*() const { return *m_ptr; }
    T * operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == NULL; }

private:
    void cloneFrom(const CRefPtr<T> & orig);
    void destroy();

    T * m_ptr;
    int * m_refCount;
};

template <typename T> CRefPtr<T>::CRefPtr()
{
    m_ptr = NULL;
    m_refCount = NULL;
}

template <typename T> CRefPtr<T>::CRefPtr(T * ptr)
{
    m_ptr = ptr;
    m_refCount = new int;
    *m_refCount = 1;
}

template <typename T> CRefPtr<T>::CRefPtr(const CRefPtr<T> & orig)
{
    cloneFrom(orig);
}

template <typename T> CRefPtr<T> & CRefPtr<T>::operator=(const CRefPtr<T> & orig)
{
    destroy();
    cloneFrom(orig);
    return *this;
}

template <typename T> CRefPtr<T> & CRefPtr<T>::operator=(T * ptr)
{
    destroy();
    m_ptr = ptr;
    m_refCount = new int;
    *m_refCount = 1;
    return *this;
}

template <typename T> void CRefPtr<T>::cloneFrom(const CRefPtr<T> & orig)
{
    this->m_ptr = orig.m_ptr;
    this->m_refCount = orig.m_refCount;
    if (m_refCount != NULL)
        (*m_refCount)++;
}

template <typename T> CRefPtr<T>::~CRefPtr()
{
    destroy();
}

template <typename T> void CRefPtr<T>::destroy()
{
    if (m_refCount != NULL)
    {
        if (*m_refCount <= 1)
        {
            delete m_ptr;
            delete m_refCount;
        }
        else
        {
            (*m_refCount)--;
        }
    }
}

#endif //GLFWASSIMP_CREFPTR_H
