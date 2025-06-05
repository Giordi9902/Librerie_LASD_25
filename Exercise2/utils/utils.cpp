#include "./utils.hpp"
using namespace std;

std::string random_string(ulong length) {
    static const std::string charset = "abcdefghijklmnopqrstuvwxyz";
    static std::default_random_engine rng(std::random_device{}());
    static std::uniform_int_distribution<size_t> dist(0, charset.size() - 1);
    std::string result;
    for (size_t i = 0; i < length; ++i)
        result += charset[dist(rng)];
    return result;
}

void wait()
{
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}
void clean()
{
    std::cout << "\033[H\033[2J\033[3J";
}

void PrintHeader()
{
    std::cout << "\033[36m"
              << R"( /$$        /$$$$$$   /$$$$$$  /$$$$$$$         /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$
| $$       /$$__  $$ /$$__  $$| $$__  $$       /$$__  $$ /$$$_  $$ /$$__  $$| $$____/
| $$      | $$  \ $$| $$  \__/| $$  \ $$      |__/  \ $$| $$$$\ $$|__/  \ $$| $$
| $$      | $$$$$$$$|  $$$$$$ | $$  | $$        /$$$$$$/| $$ $$ $$  /$$$$$$/| $$$$$$$
| $$      | $$__  $$ \____  $$| $$  | $$       /$$____/ | $$\ $$$$ /$$____/ |_____  $$
| $$      | $$  | $$ /$$  \ $$| $$  | $$      | $$      | $$ \ $$$| $$       /$$  \ $$
| $$$$$$$$| $$  | $$|  $$$$$$/| $$$$$$$/      | $$$$$$$$|  $$$$$$/| $$$$$$$$|  $$$$$$/
|________/|__/  |__/ \______/ |_______/       |________/ \______/ |________/ \______/
)" << "\033[0m"
              << std::endl;
}

void PrintPersonalTestHeader()
{
    std::cout << "\033[31m"
              << R"( /$$        /$$$$$$   /$$$$$$  /$$$$$$$        /$$$$$$$  /$$$$$$$$ /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$  /$$
| $$       /$$__  $$ /$$__  $$| $$__  $$      | $$__  $$| $$_____/| $$__  $$ /$$__  $$ /$$__  $$| $$$ | $$ /$$__  $$| $$
| $$      | $$  \ $$| $$  \__/| $$  \ $$      | $$  \ $$| $$      | $$  \ $$| $$  \__/| $$  \ $$| $$$$| $$| $$  \ $$| $$
| $$      | $$$$$$$$|  $$$$$$ | $$  | $$      | $$$$$$$/| $$$$$   | $$$$$$$/|  $$$$$$ | $$  | $$| $$ $$ $$| $$$$$$$$| $$
| $$      | $$__  $$ \____  $$| $$  | $$      | $$____/ | $$__/   | $$__  $$ \____  $$| $$  | $$| $$  $$$$| $$__  $$| $$
| $$      | $$  | $$ /$$  \ $$| $$  | $$      | $$      | $$      | $$  \ $$ /$$  \ $$| $$  | $$| $$\  $$$| $$  | $$| $$
| $$$$$$$$| $$  | $$|  $$$$$$/| $$$$$$$/      | $$      | $$$$$$$$| $$  | $$|  $$$$$$/|  $$$$$$/| $$ \  $$| $$  | $$| $$$$$$$$
|________/|__/  |__/ \______/ |_______/       |__/      |________/|__/  |__/ \______/  \______/ |__/  \__/|__/  |__/|________/
 /$$$$$$$$ /$$$$$$$$  /$$$$$$  /$$$$$$$$        /$$$$$$  /$$   /$$ /$$$$$$ /$$$$$$$$ /$$$$$$$$
|__  $$__/| $$_____/ /$$__  $$|__  $$__/       /$$__  $$| $$  | $$|_  $$_/|__  $$__/| $$_____/
   | $$   | $$      | $$  \__/   | $$         | $$  \__/| $$  | $$  | $$     | $$   | $$
   | $$   | $$$$$   |  $$$$$$    | $$         |  $$$$$$ | $$  | $$  | $$     | $$   | $$$$$
   | $$   | $$__/    \____  $$   | $$          \____  $$| $$  | $$  | $$     | $$   | $$__/
   | $$   | $$       /$$  \ $$   | $$          /$$  \ $$| $$  | $$  | $$     | $$   | $$
   | $$   | $$$$$$$$|  $$$$$$/   | $$         |  $$$$$$/|  $$$$$$/ /$$$$$$   | $$   | $$$$$$$$
   |__/   |________/ \______/    |__/          \______/  \______/ |______/   |__/   |________/
)" << "\033[0m"
              << std::endl;
}

void finalGreet()
{
    std::cout << "\033[1;33m"
              << "Thank you for using my personal test suite!\n"
              << "\033[0m" << std::endl;
    std::cout << "\033[33m"
              << R"(                                     /$$ /$$                           /$$
                                    | $$| $$                          | $$
  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$| $$$$$$$  /$$   /$$  /$$$$$$ | $$
 /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$__  $$| $$  | $$ /$$__  $$| $$
| $$  \ $$| $$  \ $$| $$  \ $$| $$  | $$| $$  \ $$| $$  | $$| $$$$$$$$|__/
| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$_____/
|  $$$$$$$|  $$$$$$/|  $$$$$$/|  $$$$$$$| $$$$$$$/|  $$$$$$$|  $$$$$$$ /$$
 \____  $$ \______/  \______/  \_______/|_______/  \____  $$ \_______/|__/
 /$$  \ $$                                         /$$  | $$
|  $$$$$$/                                        |  $$$$$$/
 \______/                                          \______/
)" << "\033[0m"
              << std::endl;
}

void MapFunctionsMenuTest(lasd::MappableContainer<int> &con)
{
    int choice;
    std::cout << "\n\t\033[1;34mSelect a map function to apply to the container:\033[0m" << std::endl;
    std::cout << "\33[1;33m\t1 :\033[0m Increment by 1" << std::endl;
    std::cout << "\33[1;33m\t2 :\033[0m Multiply by 2" << std::endl;
    std::cout << "\33[1;33m\t3 :\033[0m Subtract 5" << std::endl;
    std::cout << "\33[1;33m\t0 :\033[0m Exit\n"
              << std::endl;

    do
    {
        std::cout << "\n\033[1;34mChoice:\033[0m ";
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
        }
        if (choice < 0 || choice > 3)
        {
            std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 3.\033[0m" << std::endl;
        }
    } while (choice < 0 || choice > 3);

    switch (choice)
    {
    case 1:
    {
        con.Map(MapIncrement<int>);
        std::cout << "Elements multiplied by 2." << std::endl;
        break;
    }
    case 2:
    {
        con.Map(MapDouble<int>);
        std::cout << "10 added to each element." << std::endl;
        break;
    }
    case 3:
    {
        con.Map([](int &elem)
                { elem -= 5; });
        std::cout << "5 subtracted from each element." << std::endl;
        break;
    }
    case 0:
    {
        std::cout << "\033[1;32mExiting menu.\033[0m" << std::endl;
            break;
    }
    default:
        std::cout << "Invalid choice!" << std::endl;
        break;
    }
}

void FoldFunctionsMenuTest(lasd::TraversableContainer<int> &con)
{
    int choice;
    std::cout << "\n\t\033[1;34mSelect a fold function to apply to the container:\033[0m" << std::endl;
    std::cout << "\33[1;33m\t1 :\033[0m Sum of elements" << std::endl;
    std::cout << "\33[1;33m\t2 :\033[0m Product of elements" << std::endl;
    std::cout << "\33[1;33m\t3 :\033[0m Maximum element" << std::endl;
    std::cout << "\33[1;33m\t4 :\033[0m Minimum element" << std::endl;
    std::cout << "\33[1;33m\t0 :\033[0m Exit\n"<< std::endl;

    do
    {
        std::cout << "\n\033[1;34mChoice:\033[0m ";
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
        }
        if (choice < 0 || choice > 4)
        {
            std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 4.\033[0m" << std::endl;
        }
    } while (choice < 0 || choice > 4);

    switch (choice)
    {
    case 1:
    {
        int sum = con.Fold(FoldAdd<int>, 0);
        std::cout << "Sum of elements: " << sum << std::endl;
        break;
    }
    case 2:
    {
        int product = con.Fold(FoldMultiply<int>, 1);
        std::cout << "Product of elements: " << product << std::endl;
        break;
    }
    case 3:
    {
        int max = con.Fold(FoldMax<int>, std::numeric_limits<int>::min());
        std::cout << "Maximum element: " << max << std::endl;
        break;
    }
    case 4:
    {
        int min = con.Fold(FoldMin<int>, std::numeric_limits<int>::max());
        std::cout << "Minimum element: " << min << std::endl;
        break;
    }
    case 0:
    {
        std::cout << "\033[1;32mExiting menu.\033[0m" << std::endl;
            break;
    }
    default:
        std::cout << "Invalid choice!" << std::endl;
        break;
    }
}
