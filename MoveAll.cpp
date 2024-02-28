#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll(const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest)
{
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved = 0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  auto it = source.begin();
  while (it != source.end())
  {
    bool Found = false;
    for (const auto &kw : it->getKeywords())
    {
      if (kw == keyword)
      {
        Found = true;
        break; // Stop searching if keyword is found
      }
    }

    if (Found)
    {
      // Move the book to the destination vector
      dest.push_back(std::move(*it));
      // Erase the book from the source vector and update the iterator
      it = source.erase(it);
      ++books_moved;
    }
    else
    {
      ++it; // Move to the next book
    }
  }

  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}