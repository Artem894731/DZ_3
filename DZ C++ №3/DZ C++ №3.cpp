#include <iostream>

int n{};

int read_array_length(int& n) {
    std::cin >> n;
    return n;
}


int* memory_alloсation(int size) {
    return new int[size];
}

void read(int* arr, int size) {
    for (int i{}; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void print(int* arr, int size, std::string message = "") {
    if (!message.empty()) {
        std::cout << message;
    }
    else {
        std::cout << message;
    }
    for (int i{}; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}


void memory_deletes(int* arr) {
    delete[] arr;
    arr = nullptr;
}

//TASK 1

int* found_local_max(int* arr, int size, int& num) {
    int* arr_local_max = new int[size]{};
    num = 0;
    for (int i = 1; i < size - 1; ++i) {
        if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) {
            arr_local_max[num] = arr[i];
            num++;
        }
    }
    return arr_local_max;
}

//TASK 2

bool is_alternation_of_characters(int* arr, int size) {
    bool is_alternation = true;

    for (int i = 1; i < size; ++i) {
        if ((arr[i - 1] < 0 && arr[i] > 0) || (arr[i - 1] > 0 && arr[i] < 0)) {
            is_alternation = true;
        }
        else{
            is_alternation = false;
        }
    }
    return is_alternation;
}

//TASK 3

int count_series(int* arr, int size) {
    int length_series = 1;
    int max_series{};
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[i - 1]) {
            length_series++;
        }
        else {
            if (max_series < length_series) {
                max_series = length_series;
            }
            length_series = 1;
        }
    }
    if (max_series < length_series) {
        max_series = length_series;
    }
    return max_series;
}

int main() {

    //Task 1
    int num = 0;

    std::cout << "Task 1\n";

    std::cout << "Enter length of array: ";

    read_array_length(n);

    int* arr = memory_alloсation(n);

    std::cout << "Enter array: ";

    read(arr, n);

    print(arr, n, "Your array is: ");

    int* arr_local_max = found_local_max(arr, n, num);

    print(arr_local_max, num, "Local maximum: ");

    memory_deletes(arr);

    //Task 2
    std::cout << "\n\n" << "Task 2\n";

    std::cout << "Enter length of array: ";

    read_array_length(n);

    int* arr2 = memory_alloсation(n);

    std::cout << "Enter array: ";

    read(arr2, n);

    print(arr2, n, "Your array is: ");

    if (is_alternation_of_characters(arr2, n) == true) {
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }

    memory_deletes(arr2);

    //Task 3

    std::cout << "\n\n" << "Task 3\n";

    std::cout << "Enter length of array: ";

    read_array_length(n);

    int* arr3 = memory_alloсation(n);

    std::cout << "Enter array: ";

    read(arr3, n);

    print(arr3, n, "Your array is: ");

    std::cout << "Max series is: " << count_series(arr3, n);

    memory_deletes(arr3);

}