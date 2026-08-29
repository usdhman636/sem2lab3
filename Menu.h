#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Queue.h"

inline void PrintQueue(const Queue<int>& q)
{
    Queue<int> copy(q);

    while(copy.GetLength() > 0)
    {
        std::cout << copy.Dequeue() << " ";
    }

    std::cout << std::endl;
}

inline int ReadInt()
{
    int value;

    while (!(std::cin >> value))
    {
        std::cout << "Invalid input. Enter a number: ";

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }

    return value;
}

inline void RunMenu()
{
    Queue<int> queue;

    int choice;
    int value;
    do
    {

        std::cout << "\n===== QUEUE MENU =====\n";
	std::cout << "1. Enqueue\n";
	std::cout << "2. Dequeue\n";
	std::cout << "3. Front\n";
	std::cout << "4. Length\n";
	std::cout << "5. Print queue\n";
	std::cout << "6. Map (*2)\n";
	std::cout << "7. Where (even numbers)\n";
	std::cout << "8. Reduce (sum)\n";
	std::cout << "9. Concat queue\n";
	std::cout << "10. Get subqueue\n";
	std::cout << "11. Find subqueue\n";
	std::cout << "12. Split (even/odd)\n";
	std::cout << "0. Exit\n";

        choice = ReadInt();

        try
        {
            switch(choice)
            {
                case 1:
                {

                    std::cout << "Value: ";
                    value = ReadInt();

                    queue.Enqueue(value);

                    break;
                }

                case 2:
                {
                    std::cout
                        << "Removed: "
                        << queue.Dequeue()
                        << std::endl;

                    break;
                }

                case 3:
                {
                    std::cout
                        << "Front: "
                        << queue.Front()
                        << std::endl;

                    break;
                }

                case 4:
                {
                    std::cout
                        << "Length: "
                        << queue.GetLength()
                        << std::endl;

                    break;
                }

                case 5:
                {
                    PrintQueue(queue);

                    break;
                }

		case 6:
		{
		    Queue<int> result =
		        queue.Map([](int x)
		        {
		            return x * 2;
		        });

		    std::cout << "Mapped queue:\n";

		    PrintQueue(result);

		    break;
		}

		case 7:
		{
		    Queue<int> result =
		        queue.Where([](int x)
		        {
		            return x % 2 == 0;
		        });

		    std::cout << "Even elements:\n";

		    PrintQueue(result);

		    break;
		}

		case 8:
		{
		    int sum =
		        queue.Reduce(
		            [](int a, int b)
		            {
		                return a + b;
		            },
		            0
		        );

		    std::cout
		        << "Sum = "
		        << sum
		        << std::endl;

		    break;
		}

		case 9:
		{
		    Queue<int> second;

		    int count;

		    std::cout
		        << "How many elements in second queue? ";

		    count = ReadInt();

		    for(int i = 0; i < count; i++)
		    {
		        std::cout
		            << "Element "
		            << i + 1
		            << ": ";

		        second.Enqueue(ReadInt());
		    }

		    Queue<int> result =
		        queue.Concat(second);

		    std::cout
		        << "Result queue:\n";

		    PrintQueue(result);

		    break;
		}

		case 10:
		{
		    int start;
		    int end;

		    std::cout << "Start index: ";
		    start = ReadInt();

		    std::cout << "End index: ";
		    end = ReadInt();

		    Queue<int> result =
		        queue.GetSubQueue(start, end);

		    PrintQueue(result);

		    break;
		}

		case 11:
		{
		    Queue<int> sub;

		    int count;

		    std::cout
		        << "Subqueue size: ";

		    count = ReadInt();

		    for(int i = 0; i < count; i++)
		    {
		        std::cout
		            << "Element "
		            << i + 1
		            << ": ";

		        sub.Enqueue(ReadInt());
		    }

		    int position =
		        queue.FindSubQueue(sub);

		    std::cout
		        << "Position = "
		        << position
		        << std::endl;

		    break;
		}

		case 12:
		{
		    Queue<int> evenQueue;
		    Queue<int> oddQueue;

		    queue.Split(
		        [](int x)
		        {
		            return x % 2 == 0;
		        },
		        evenQueue,
		        oddQueue
		    );

		    std::cout
		        << "Even queue:\n";

		    PrintQueue(evenQueue);

		    std::cout
		        << "Odd queue:\n";

		    PrintQueue(oddQueue);

		    break;
		}
            }
        }
        catch(const std::exception& e)
        {
            std::cout
                << "Error: "
                << e.what()
                << std::endl;
        }

    } while(choice != 0);
}

#endif
