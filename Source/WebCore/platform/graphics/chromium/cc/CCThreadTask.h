/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef CCThreadTask_h
#define CCThreadTask_h

#include "CCThread.h"
#include <wtf/PassOwnPtr.h>
#include <wtf/PassRefPtr.h>

namespace WebCore {

template<typename T>
class CCThreadTask0 : public CCThread::Task {
public:
    typedef void (T::*Method)();
    typedef CCThreadTask0<T> CCThreadTaskImpl;

    static PassOwnPtr<CCThreadTaskImpl> create(T* instance, Method method)
    {
        return adoptPtr(new CCThreadTaskImpl(instance, method));
    }

private:
    CCThreadTask0(T* instance, Method method)
        : CCThread::Task(instance)
        , m_method(method)
    {
    }

    virtual void performTask() OVERRIDE
    {
        (*static_cast<T*>(instance()).*m_method)();
    }

private:
    Method m_method;
};

template<typename T, typename P1, typename MP1>
class CCThreadTask1 : public CCThread::Task {
public:
    typedef void (T::*Method)(MP1);
    typedef CCThreadTask1<T, P1, MP1> CCThreadTaskImpl;

    static PassOwnPtr<CCThreadTaskImpl> create(T* instance, Method method, P1 parameter1)
    {
        return adoptPtr(new CCThreadTaskImpl(instance, method, parameter1));
    }

private:
    CCThreadTask1(T* instance, Method method, P1 parameter1)
        : CCThread::Task(instance)
        , m_method(method)
        , m_parameter1(parameter1)
    {
    }

    virtual void performTask() OVERRIDE
    {
        (*static_cast<T*>(instance()).*m_method)(m_parameter1);
    }

private:
    Method m_method;
    P1 m_parameter1;
};

template<typename T, typename P1, typename MP1, typename P2, typename MP2>
class CCThreadTask2 : public CCThread::Task {
public:
    typedef void (T::*Method)(MP1, MP2);
    typedef CCThreadTask2<T, P1, MP1, P2, MP2> CCThreadTaskImpl;

    static PassOwnPtr<CCThreadTaskImpl> create(T* instance, Method method, P1 parameter1, P2 parameter2)
    {
        return adoptPtr(new CCThreadTaskImpl(instance, method, parameter1, parameter2));
    }

private:
    CCThreadTask2(T* instance, Method method, P1 parameter1, P2 parameter2)
        : CCThread::Task(instance)
        , m_method(method)
        , m_parameter1(parameter1)
        , m_parameter2(parameter2)
    {
    }

    virtual void performTask() OVERRIDE
    {
        (*static_cast<T*>(instance()).*m_method)(m_parameter1, m_parameter2);
    }

private:
    Method m_method;
    P1 m_parameter1;
    P2 m_parameter2;
};

template<typename T, typename P1, typename MP1, typename P2, typename MP2, typename P3, typename MP3>
class CCThreadTask3 : public CCThread::Task {
public:
    typedef void (T::*Method)(MP1, MP2, MP3);
    typedef CCThreadTask3<T, P1, MP1, P2, MP2, P3, MP3> CCThreadTaskImpl;

    static PassOwnPtr<CCThreadTaskImpl> create(T* instance, Method method, P1 parameter1, P2 parameter2, P3 parameter3)
    {
        return adoptPtr(new CCThreadTaskImpl(instance, method, parameter1, parameter2, parameter3));
    }

private:
    CCThreadTask3(T* instance, Method method, P1 parameter1, P2 parameter2, P3 parameter3)
        : CCThread::Task(instance)
        , m_method(method)
        , m_parameter1(parameter1)
        , m_parameter2(parameter2)
        , m_parameter3(parameter3)
    {
    }

    virtual void performTask() OVERRIDE
    {
        (*static_cast<T*>(instance()).*m_method)(m_parameter1, m_parameter2, m_parameter3);
    }

private:
    Method m_method;
    P1 m_parameter1;
    P2 m_parameter2;
    P3 m_parameter3;
};


template<typename T, typename P1, typename MP1, typename P2, typename MP2, typename P3, typename MP3, typename P4, typename MP4>
class CCThreadTask4 : public CCThread::Task {
public:
    typedef void (T::*Method)(MP1, MP2, MP3, MP4);
    typedef CCThreadTask4<T, P1, MP1, P2, MP2, P3, MP3, P4, MP4> CCThreadTaskImpl;

    static PassOwnPtr<CCThreadTaskImpl> create(T* instance, Method method, P1 parameter1, P2 parameter2, P3 parameter3, P4 parameter4)
    {
        return adoptPtr(new CCThreadTaskImpl(instance, method, parameter1, parameter2, parameter3, parameter4));
    }

private:
    CCThreadTask4(T* instance, Method method, P1 parameter1, P2 parameter2, P3 parameter3, P4 parameter4)
        : CCThread::Task(instance)
        , m_method(method)
        , m_parameter1(parameter1)
        , m_parameter2(parameter2)
        , m_parameter3(parameter3)
        , m_parameter4(parameter4)
    {
    }

    virtual void performTask() OVERRIDE
    {
        (*static_cast<T*>(instance()).*m_method)(m_parameter1, m_parameter2, m_parameter3, m_parameter4);
    }

private:
    Method m_method;
    P1 m_parameter1;
    P2 m_parameter2;
    P3 m_parameter3;
    P4 m_parameter4;
};

template<typename T, typename P1, typename MP1, typename P2, typename MP2, typename P3, typename MP3, typename P4, typename MP4, typename P5, typename MP5>
class CCThreadTask5 : public CCThread::Task {
public:
    typedef void (T::*Method)(MP1, MP2, MP3, MP4, MP5);
    typedef CCThreadTask5<T, P1, MP1, P2, MP2, P3, MP3, P4, MP4, P5, MP5> CCThreadTaskImpl;

    static PassOwnPtr<CCThreadTaskImpl> create(T* instance, Method method, P1 parameter1, P2 parameter2, P3 parameter3, P4 parameter4, P5 parameter5)
    {
        return adoptPtr(new CCThreadTaskImpl(instance, method, parameter1, parameter2, parameter3, parameter4, parameter5));
    }

private:
    CCThreadTask5(T* instance, Method method, P1 parameter1, P2 parameter2, P3 parameter3, P4 parameter4, P5 parameter5)
        : CCThread::Task(instance)
        , m_method(method)
        , m_parameter1(parameter1)
        , m_parameter2(parameter2)
        , m_parameter3(parameter3)
        , m_parameter4(parameter4)
        , m_parameter5(parameter5)
    {
    }

    virtual void performTask() OVERRIDE
    {
        (*static_cast<T*>(instance()).*m_method)(m_parameter1, m_parameter2, m_parameter3, m_parameter4, m_parameter5);
    }

private:
    Method m_method;
    P1 m_parameter1;
    P2 m_parameter2;
    P3 m_parameter3;
    P4 m_parameter4;
    P5 m_parameter5;
};

template<typename T>
PassOwnPtr<CCThread::Task> createCCThreadTask(
    T* const callee,
    void (T::*method)());

template<typename T>
PassOwnPtr<CCThread::Task> createCCThreadTask(
    T* const callee,
    void (T::*method)())
{
    return CCThreadTask0<T>::create(
        callee,
        method);
}

template<typename T, typename P1, typename MP1>
PassOwnPtr<CCThread::Task> createCCThreadTask(
    T* const callee,
    void (T::*method)(MP1),
    const P1& parameter1)
{
    return CCThreadTask1<T, P1, MP1>::create(
        callee,
        method,
        parameter1);
}

template<typename T, typename P1, typename MP1, typename P2, typename MP2>
PassOwnPtr<CCThread::Task> createCCThreadTask(
    T* const callee,
    void (T::*method)(MP1, MP2),
    const P1& parameter1,
    const P2& parameter2)
{
    return CCThreadTask2<T, P1, MP1, P2, MP2>::create(
        callee,
        method,
        parameter1,
        parameter2);
}

template<typename T, typename P1, typename MP1, typename P2, typename MP2, typename P3, typename MP3>
PassOwnPtr<CCThread::Task> createCCThreadTask(
    T* const callee,
    void (T::*method)(MP1, MP2, MP3),
    const P1& parameter1,
    const P2& parameter2,
    const P3& parameter3)
{
    return CCThreadTask3<T, P1, MP1, P2, MP2, P3, MP3>::create(
        callee,
        method,
        parameter1,
        parameter2,
        parameter3);
}

template<typename T, typename P1, typename MP1, typename P2, typename MP2, typename P3, typename MP3, typename P4, typename MP4>
PassOwnPtr<CCThread::Task> createCCThreadTask(
    T* const callee,
    void (T::*method)(MP1, MP2, MP3, MP4),
    const P1& parameter1,
    const P2& parameter2,
    const P3& parameter3,
    const P4& parameter4)
{
    return CCThreadTask4<T, P1, MP1, P2, MP2, P3, MP3, P4, MP4>::create(
        callee,
        method,
        parameter1,
        parameter2,
        parameter3,
        parameter4);

}

template<typename T, typename P1, typename MP1, typename P2, typename MP2, typename P3, typename MP3, typename P4, typename MP4, typename P5, typename MP5>
PassOwnPtr<CCThread::Task> createCCThreadTask(
    T* const callee,
    void (T::*method)(MP1, MP2, MP3, MP4, MP5),
    const P1& parameter1,
    const P2& parameter2,
    const P3& parameter3,
    const P4& parameter4,
    const P5& parameter5)
{
    return CCThreadTask5<T, P1, MP1, P2, MP2, P3, MP3, P4, MP4, P5, MP5>::create(
        callee,
        method,
        parameter1,
        parameter2,
        parameter3,
        parameter4,
        parameter5);

}

} // namespace WebCore

#endif // CCThreadTask_h
