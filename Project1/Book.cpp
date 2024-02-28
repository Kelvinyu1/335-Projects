#include "Book.hpp"
// write and document all methods in this file.
Book::Book()
{
    title_ = "";
    author_ = "";
    ISBN_ = 0;
    icon_ = nullptr;
    price_ = 0;
    blurb_ = "";
}

Book::~Book()
{
}

Book::Book(const Book &rhs)
{
    title_ = rhs.title_;
    author_ = rhs.author_;
    ISBN_ = rhs.ISBN_;
    price_ = rhs.price_;
    keywords_ = rhs.keywords_;
    blurb_ = rhs.blurb_;

    if (rhs.icon_)
    {
        icon_ = new int[80]; // Allocate memory
        for (int i = 0; i < 80; i++)
        {
            icon_[i] = rhs.icon_[i];
        }
    }
    else
    {
        icon_ = nullptr;
    }
}

Book &Book::operator=(const Book &rhs)
{
    if (this != &rhs)
    { // Check for self-assignment
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;

        if (rhs.icon_)
        {
            icon_ = new int[80]; // Allocate new memory
            for (int i = 0; i < 80; i++)
            {
                icon_[i] = rhs.icon_[i];
            }
        }
        else
        {
            icon_ = nullptr;
        }
    }
    return *this;
}

Book::Book(Book &&rhs) //&&: rvalue reference, move constructor
{
    title_ = std::move(rhs.title_);
    author_ = std::move(rhs.author_);
    ISBN_ = std::move(rhs.ISBN_);
    icon_ = rhs.icon_;
    rhs.icon_ = nullptr;
    price_ = std::move(rhs.price_);
    keywords_ = std::move(rhs.keywords_);
    blurb_ = std::move(rhs.blurb_);
}

Book &Book::operator=(Book &&rhs)
{
    if (this != &rhs)
    { // Avoid self-assignment
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        price_ = std::move(rhs.price_);
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);

        delete[] icon_; // Correctly handle existing icon_
        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;
    }
    return *this;
}

const std::string &Book::getTitle() const
{
    return title_;
}

void Book::setTitle(const std::string &title)
{
    title_ = title;
}

const std::string &Book::getAuthor() const
{
    return author_;
}

void Book::setAuthor(const std::string &author)
{
    author_ = author;
}

long long int Book::getISBN() const
{
    return ISBN_;
}

void Book::setISBN(long long int ISBN)
{
    ISBN_ = ISBN;
}

const int *Book::getIcon() const
{
    return icon_;
}

void Book::setIcon(int *icon)
{
    icon_ = icon;
}

float Book::getPrice() const
{
    return price_;
}

void Book::setPrice(float price)
{
    price_ = price;
}

const std::vector<std::string> &Book::getKeywords() const
{
    return keywords_;
}

void Book::setKeywords(const std::vector<std::string> &keywords)
{
    keywords_ = keywords;
}

const std::string &Book::getBlurb() const
{
    return blurb_;
}

void Book::setBlurb(const std::string &blurb)
{
    blurb_ = blurb;
} 

void Book::print() const
{
    std::cout << "Title: " << title_ << "\n";
    std::cout << "Author: " << author_ << "\n";
    std::cout << "ISBN: " << ISBN_ << "\n";
    std::cout << "price: $" << price_ << "\n";
    std::cout << "blurb: " << blurb_ << "\n";
    std::cout << "icon: ";
    for(int i = 0; i < 80; i++){
        std::cout << icon_[i] << " ";
    }
    std::cout << "\n";
    std::cout << "keywords: ";
    
    for(int i = 0; i < 2; i++){
        std::cout << keywords_[i] << " ";
    }
    std::cout << "\n";
}
