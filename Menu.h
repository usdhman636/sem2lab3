#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Queue.h"
#include <string>

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



inline std::string ReadString()
{
    std::string value;
    std::cin >> value;
    return value;
}

inline void PrintStringQueue(const Queue<std::string>& q)
{
    Queue<std::string> copy(q);
    while (copy.GetLength() > 0)
    {
        std::cout << copy.Dequeue() << " ";
    }
    std::cout << std::endl;
}

inline void RunStringMenu()
{
    Queue<std::string> queue;
    int choice;
    std::string value;

    do
    {
        std::cout << "\n===== STRING QUEUE MENU =====\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Front\n";
        std::cout << "4. Length\n";
        std::cout << "5. Print queue\n";
        std::cout << "6. Map (Uppercase)\n";
        std::cout << "7. Where (Length > 3)\n";
        std::cout << "8. Reduce (Concatenate strings)\n";
        std::cout << "9. Concat queue\n";
        std::cout << "10. Get subqueue\n";
        std::cout << "11. Find subqueue\n";
        std::cout << "12. Split (Length > 3 / <= 3)\n";
        std::cout << "0. Exit\n";

        choice = ReadInt();

        try
        {
            switch (choice)
            {
                case 1:
                {
                    std::cout << "Value: ";
                    value = ReadString();
                    queue.Enqueue(value);
                    break;
                }

                case 2:
                {
                    std::cout << "Removed: " << queue.Dequeue() << std::endl;
                    break;
                }

                case 3:
                {
                    std::cout << "Front: " << queue.Front() << std::endl;
                    break;
                }

                case 4:
                {
                    std::cout << "Length: " << queue.GetLength() << std::endl;
                    break;
                }

                case 5:
                {
                    PrintStringQueue(queue);
                    break;
                }

                case 6:
                {
                    Queue<std::string> result = queue.Map([](std::string s)
                    {
                        for (auto &c : s) c = toupper(c);
                        return s;
                    });
                    std::cout << "Mapped queue (Uppercase):\n";
                    PrintStringQueue(result);
                    break;
                }

                case 7:
                {
                    Queue<std::string> result = queue.Where([](std::string s)
                    {
                        return s.length() > 3;
                    });
                    std::cout << "Strings with length > 3:\n";
                    PrintStringQueue(result);
                    break;
                }

                case 8:
                {
                    std::string concatenated = queue.Reduce(
                        [](std::string elem, std::string acc)
                        {
                            return acc.empty() ? elem : acc + " " + elem;
                        },
                        std::string("")
                    );
                    std::cout << "Concatenated = " << concatenated << std::endl;
                    break;
                }

                case 9:
                {
                    Queue<std::string> second;
                    std::cout << "How many elements in second queue? ";
                    int count = ReadInt();

                    for (int i = 0; i < count; i++)
                    {
                        std::cout << "Element " << i + 1 << ": ";
                        second.Enqueue(ReadString());
                    }

                    Queue<std::string> result = queue.Concat(second);
                    std::cout << "Result queue:\n";
                    PrintStringQueue(result);
                    break;
                }

                case 10:
                {
                    std::cout << "Start index: ";
                    int start = ReadInt();
                    std::cout << "End index: ";
                    int end = ReadInt();

                    Queue<std::string> result = queue.GetSubQueue(start, end);
                    PrintStringQueue(result);
                    break;
                }

                case 11:
                {
                    Queue<std::string> sub;
                    std::cout << "Subqueue size: ";
                    int count = ReadInt();

                    for (int i = 0; i < count; i++)
                    {
                        std::cout << "Element " << i + 1 << ": ";
                        sub.Enqueue(ReadString());
                    }

                    int position = queue.FindSubQueue(sub);
                    std::cout << "Position = " << position << std::endl;
                    break;
                }

                case 12:
                {
                    Queue<std::string> longStrings;
                    Queue<std::string> shortStrings;

                    queue.Split(
                        [](std::string s)
                        {
                            return s.length() > 3;
                        },
                        longStrings,
                        shortStrings
                    );

                    std::cout << "Strings (length > 3):\n";
                    PrintStringQueue(longStrings);

                    std::cout << "Strings (length <= 3):\n";
                    PrintStringQueue(shortStrings);

                    break;
                }
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } while (choice != 0);
}


#endif
