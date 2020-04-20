#include <iostream>
#include <fstream>
#include <Windows.h>

#define STRING_MAX_LENGHT 256
#define BOOK_MAX_LENGHT 256
#define FILE_NAME "file.dat"

static class Display {
protected:
	static HANDLE hConsole;
public:
	static void setWhiteTextColor() {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	static void setGreenTextColor() {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	}
};

HANDLE Display::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Serializable {
protected:
	mutable bool isTracking;
	static const char delimiter = ',';
public:
	virtual std::ostream& serialize(std::ostream& out) const = 0;
	virtual std::istream& deserialize(std::istream& out) = 0;
	Serializable()
	{
		isTracking = false;
	}

	bool getIsTracking() const {
		return isTracking;
	}
};

class Book : public Serializable {
protected:
	char Author[STRING_MAX_LENGHT];
	char Publisher[STRING_MAX_LENGHT];
	int NumOfThomes;
	char LibraryCode[STRING_MAX_LENGHT];
public:

	Book() : Serializable()
	{

	}

	const char* getAuthor() const {
		return Author;
	}
	void setAuthor(char author[STRING_MAX_LENGHT]) {
		isTracking = false;
		strncpy_s(Author, author, STRING_MAX_LENGHT);
	}

	const char* getPublisher() const {
		return Publisher;
	}
	void setPublisher(char publisher[STRING_MAX_LENGHT]) {
		isTracking = false;
		strncpy_s(Publisher, publisher, STRING_MAX_LENGHT);
	}

	const char* getLibraryCode() const {
		return LibraryCode;
	}
	void setLibraryCode(char libraryCode[STRING_MAX_LENGHT]) {
		isTracking = false;
		strncpy_s(LibraryCode, libraryCode, STRING_MAX_LENGHT);
	}

	int getNumOfThomes() const {
		return NumOfThomes;
	}
	void setNumOfThomes(int numOfThomes) {
		isTracking = false;
		NumOfThomes = numOfThomes;
	}

	std::ostream& serialize(std::ostream& out) const {
		out << NumOfThomes;
		out << delimiter;
		out.write(Author, STRING_MAX_LENGHT);
		out.write(Publisher, STRING_MAX_LENGHT);
		out.write(LibraryCode, STRING_MAX_LENGHT);

		isTracking = true;

		return out;
	}
	std::istream& deserialize(std::istream& in) {
		if (in) {
			char del;
			in >> NumOfThomes;
			in >> del;
			in.read(Author, STRING_MAX_LENGHT);
			in.read(Publisher, STRING_MAX_LENGHT);
			in.read(LibraryCode, STRING_MAX_LENGHT);
		}

		isTracking = true;

		return in;
	}

	void print(std::ostream& out) {
		if (!isTracking) {
			Display::setGreenTextColor();
		}
		std::cout << "Author: " << Author << "\tNum of thomes: " << NumOfThomes << "\tPublisher: " << Publisher << "\tLibraryCode: " << LibraryCode << "\n";
		Display::setWhiteTextColor();
	}
};

std::ofstream& operator<<(std::ofstream& out, const Serializable& obj)
{
	obj.serialize(out);
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Serializable& obj)
{
	obj.deserialize(in);
	return in;
}

int currentBookCount = 0;
Book books[BOOK_MAX_LENGHT];

void printBooks();
int menu();
void addNewBook();
void deleteBook(int index);
void editBook(int index);
int editBookMenu();
bool myComparer(Book book1, Book book2);
template <typename T>
void mergeSort(T* arr, int size, bool(*comparer)(T, T));
void saveToFile(std::string fileName, Book const * const objects, int size);
void readFromFile(std::string fileName, Book * const objects, int maxSize);

int main() {
	readFromFile(FILE_NAME, books, BOOK_MAX_LENGHT);
	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 1:
			printBooks();
			break;
		case 2:
			addNewBook();
			break;
		case 3:
		{
			int index;
			std::cout << "Enter book index you want to delete: ";
			std::cin >> index;
			deleteBook(index - 1);
		}
			break;
		case 4:
		{
			int index;
			printBooks();
			std::cout << "Enter book index you want to edit: ";
			std::cin >> index;
			editBook(index - 1);
		}
		case 5:
		{
			bool(*comparer)(Book, Book) = myComparer;
			mergeSort(books, currentBookCount, comparer);
		}
			break;
		case 6:
			saveToFile(FILE_NAME, books, currentBookCount);
			break;
		case 7:
			readFromFile(FILE_NAME, books, BOOK_MAX_LENGHT);
			break;
		case 8:
			isExit = true;
			break;
		default:
			std::cout << "Wrong operation";
			break;
		}
	}
}

void printBooks()
{
	for (int i = 0; i < currentBookCount; ++i) {
		std::cout << "[" << i + 1 << "]";
		books[i].print(std::cout);
	}
}

int menu() {
	std::cout << "[1] Show books" << std::endl;
	std::cout << "[2] Add new book" << std::endl;
	std::cout << "[3] Delete book" << std::endl;
	std::cout << "[4] Edit book" << std::endl;
	std::cout << "[5] Sort" << std::endl;
	std::cout << "[6] Save to file" << std::endl;
	std::cout << "[7] Read from file" << std::endl;
	std::cout << "[8] Exit" << std::endl;

	std::cout << "Select operation: ";
	int operation = 0;
	std::cin >> operation;

	return operation;
}

void addNewBook()
{
	Book book;
	std::cout << "Author: ";

	std::cin.ignore();
	char author[STRING_MAX_LENGHT];
	std::cin.getline(author, STRING_MAX_LENGHT);
	book.setAuthor(author);

	char publisher[STRING_MAX_LENGHT];
	std::cout << "Publisher: ";
	std::cin.getline(publisher, STRING_MAX_LENGHT);
	book.setPublisher(publisher);

	char libraryCode[STRING_MAX_LENGHT];
	std::cout << "Library code: ";
	std::cin.getline(libraryCode, STRING_MAX_LENGHT);
	book.setLibraryCode(libraryCode);

	int numOfThomes;
	std::cout << "Number of thomes: ";
	std::cin >> numOfThomes;
	book.setNumOfThomes(numOfThomes);

	books[currentBookCount] = book;

	++currentBookCount;
}

void deleteBook(int index)
{
	for (int i = index; i < currentBookCount - 1; ++i) {
		books[i] = books[i + 1];
	}
	currentBookCount--;
}

void editBook(int index)
{
	Book& book = books[index];

	bool isEditing = true;
	while (isEditing) {
		switch (editBookMenu()) {
		case 1:
			std::cout << "Enter new author: ";
			std::cin.ignore();
			char author[STRING_MAX_LENGHT];
			std::cin.getline(author, STRING_MAX_LENGHT);
			book.setAuthor(author);
			break;
		case 2:
			std::cout << "Enter new publisher: ";
			std::cin.ignore();
			char publisher[STRING_MAX_LENGHT];
			std::cin.getline(publisher, STRING_MAX_LENGHT);
			book.setPublisher(publisher);
			break;
		case 3:
			std::cout << "Enter number of thomes: ";
			int numOfThomes;
			std::cin >> numOfThomes;
			book.setNumOfThomes(numOfThomes);
			break;
		case 4:
			std::cout << "Enter new library code: ";
			std::cin.ignore();
			char libraryCode[STRING_MAX_LENGHT];
			std::cin.getline(libraryCode, STRING_MAX_LENGHT);
			book.setLibraryCode(libraryCode);
			break;
		case 5:
			isEditing = false;
			break;
		default:
			std::cout << "Wrong operation, try again";
			break;
		}
	}
}

int editBookMenu()
{
	int operation;
	std::cout << "[1] Author" << std::endl;
	std::cout << "[2] Publisher" << std::endl;
	std::cout << "[3] Num of thomes" << std::endl;
	std::cout << "[4] Library code" << std::endl;
	std::cout << "[5] Stop editing" << std::endl;
	std::cout << "Select property you want to edit: ";
	std::cin >> operation;

	return operation;
}

template <typename T>
void mergeSort(T* arr, int size, bool(*comparer)(T, T)) {
	int firstArrIndex = 0;
	int firstArrSize = size / 2;
	int secondArrIndex = size / 2;
	int secondArrSize = size - size / 2;

	T* tmpArr1 = new T[firstArrSize];
	T* tmpArr2 = new T[secondArrSize];

	memcpy(tmpArr1, arr, sizeof(T) * firstArrSize);
	memcpy(tmpArr2, arr + firstArrSize, sizeof(T) * secondArrSize);

	if (size > 2) {
		mergeSort(tmpArr1, secondArrIndex, comparer);
		mergeSort(tmpArr2, secondArrSize, comparer);
	}

	int firstIndex = 0;
	int secondIndex = 0;
	for (int i = 0; i < size; ++i) {
		bool isTakeFromFirstArray = true;
		if (firstIndex >= firstArrSize) {
			isTakeFromFirstArray = false;
		}
		else if (secondIndex >= secondArrSize) {
			isTakeFromFirstArray = true;
		}
		else {
			isTakeFromFirstArray = comparer(tmpArr1[firstIndex], tmpArr2[secondIndex]);
		}

		if (isTakeFromFirstArray) {
			arr[i] = tmpArr1[firstIndex];
			++firstIndex;
		}
		else {
			arr[i] = tmpArr2[secondIndex];
			++secondIndex;
		}
	}

	delete[] tmpArr1;
	delete[] tmpArr2;
}

bool myComparer(Book book1, Book book2) {
	int index = 0;
	while (index < STRING_MAX_LENGHT && book1.getAuthor()[index] != '\0' && book2.getAuthor()[index] != '\0') {
		if (book1.getAuthor()[index] > book2.getAuthor()[index]) {
			return true;
		}
		else if (book1.getAuthor()[index] < book2.getAuthor()[index]) {
			return false;
		}
		else {
			++index;
		}
	}
}

void saveToFile(std::string fileName, Book const* const objects, int size)
{
	std::ofstream fout(fileName, std::ios::binary | std::ios::app);
	
	if (!fout.is_open()) {
		std::cout << "Error, file " << fileName << " not opened" << std::endl;
		return;
	}

	for (int i = 0; i < size; ++i) {
		fout << objects[i];
	}

	fout.close();
}


void readFromFile(std::string fileName, Book* const objects, int maxSize)
{
	std::ifstream fin(fileName, std::ios::binary);

	if (!fin.is_open()) {
		std::cout << "Error, file " << fileName << " not opened" << std::endl;
		return;
	}

	currentBookCount = 0;
	while (fin >> objects[currentBookCount] && currentBookCount < maxSize) {
		++currentBookCount;
	}

	fin.close();
}