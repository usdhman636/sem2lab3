#include "Tests.h"
#include "Queue.h"

#include <cassert>
#include <iostream>
#include <chrono>

void TestEnqueue()
{
    Queue<int> q;

    q.Enqueue(10);
    q.Enqueue(20);

    assert(q.GetLength() == 2);
}

void TestDequeue()
{
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);

    int value = q.Dequeue();

    assert(value == 1);
    assert(q.GetLength() == 1);
}

void TestConcat()
{
    Queue<int> q1;
    Queue<int> q2;

    q1.Enqueue(1);
    q1.Enqueue(2);

    q2.Enqueue(3);
    q2.Enqueue(4);

    Queue<int> result = q1.Concat(q2);

    assert(result.GetLength() == 4);
}

void TestMap()
{
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    Queue<int> result =
        q.Map([](int x)
        {
            return x * 2;
        });

    assert(result.Front() == 2);
}

void TestWhere()
{
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    Queue<int> result =
        q.Where([](int x)
        {
            return x % 2 == 0;
        });

    assert(result.GetLength() == 2);
}

void TestReduce()
{
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    int sum =
        q.Reduce(
            [](int a, int b)
            {
                return a + b;
            },
            0
        );

    assert(sum == 6);
}

void TestSubQueue()
{
    Queue<int> q;

    for(int i=1;i<=5;i++)
        q.Enqueue(i);

    Queue<int> sub = q.GetSubQueue(1,3);

    assert(sub.GetLength() == 3);
}

void TestFindSubQueue()
{
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    Queue<int> sub;

    sub.Enqueue(2);
    sub.Enqueue(3);

    assert(q.FindSubQueue(sub) == 1);
}

void TestCopyConstructor()
{
    Queue<int> q1;

    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    Queue<int> q2(q1);

    assert(q2.GetLength() == 3);
    assert(q2.Front() == 1);
}

void TestAssignment()
{
    Queue<int> q1;

    q1.Enqueue(10);
    q1.Enqueue(20);

    Queue<int> q2;

    q2 = q1;

    assert(q2.GetLength() == 2);
    assert(q2.Front() == 10);
}

void RunAllTests()
{
    TestEnqueue();
    TestDequeue();
    TestConcat();
    TestMap();
    TestWhere();
    TestReduce();
    TestSubQueue();
    TestFindSubQueue();
    TestCopyConstructor();
    TestAssignment();
    std::cout << "All tests passed!" << std::endl;
}

void PerformanceTest()
{
    Queue<int> q;

    auto start =
        std::chrono::high_resolution_clock::now();

    for(int i=0;i<10000;i++)
        q.Enqueue(i);

    auto end =
        std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast
        <
            std::chrono::milliseconds
        >(end - start);

    std::cout
        << "Enqueue 10000 elements: "
        << duration.count()
        << " ms"
        << std::endl;
}
