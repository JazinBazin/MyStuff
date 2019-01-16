#pragma once

class Singleton1 {
public:
    static Singleton1& instance() {
        return singleton;
    }

    void setData(int newData) {
        data = newData;
    }

    int& getData() {
        return data;
    }

private:
    Singleton1(int d) : data(d) {}
    Singleton1(const Singleton1 &other);
    Singleton1& operator=(const Singleton1 &other);

private:
    int data;
    static Singleton1 singleton;
};

Singleton1 Singleton1::singleton(0);

class Singleton2 {
public:
    static Singleton2& instance() {
        static Singleton2 singleton(0);
        return singleton;
    }

    void setData(int newData) {
        data = newData;
    }

    int& getData() {
        return data;
    }

private:
    Singleton2(int d) : data(d) {}
    Singleton2(const Singleton2 &other);
    Singleton2& operator=(const Singleton2 &other);

private:
    int data;
};

template <typename T>
class Singleton {
public:
    static T& instance() {
        static T theInstance;
        return theInstance;
    }
protected:
    Singleton() {}
    virtual ~Singleton() {}
private:
    Singleton(const Singleton &other);
    Singleton& operator=(const Singleton &other);
};

class MyClass : public Singleton<MyClass> {
    friend class Singleton;
public:
    void setData(int d) {
        data = d;
    }
    int& getData() {
        return data;
    }

protected:
    MyClass() :
        data(0) {}

private:
    int data;
};





























