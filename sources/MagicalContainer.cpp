#include "MagicalContainer.hpp"
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
using namespace ariel;

// Help function
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Macigal Container

MagicalContainer::MagicalContainer() {}
MagicalContainer::~MagicalContainer() {}

void MagicalContainer::addElement(int num)
{
    // Find the correct position for insertion in magicalContainer
   auto magicalIt = std::lower_bound(magicalContainer.begin(), magicalContainer.end(), num);
   // Insert the new element at the found position
    magicalContainer.insert(magicalIt, num);

    if (isPrime(num))
    {
         // Create a new pointer for the prime number
        int* newNum = new int(num);
        auto primeIt = std::lower_bound(primeMagicalContainer.begin(), primeMagicalContainer.end(), newNum,
            [](const int* a, const int* b) { return *a < *b; });
        primeMagicalContainer.insert(primeIt, newNum);
    }
}

void MagicalContainer::removeElement(int num)
{
    bool isFound = false;
    for (auto it = magicalContainer.begin(); it != magicalContainer.end(); ++it)
    {
        if (*it == num)
        {
            magicalContainer.erase(it);
            isFound = true;
            break;
        }
    }
    if (!isFound)
    {
        throw std::runtime_error("The element is not found");
    }
}

int MagicalContainer::size()
{
    return magicalContainer.size();
}

// Ascending Iterator
// Constructors
MagicalContainer::AscendingIterator::AscendingIterator() : ascIter(nullptr), i(0) {}
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : ascIter(other.ascIter), i(other.i) {}
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicalContainer) : ascIter(&magicalContainer), i(0) {}
MagicalContainer::AscendingIterator::~AscendingIterator() {}

// Operators
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this->ascIter != other.ascIter)
    {
        throw runtime_error("These are different containers");
    }

    if (this != &other)
    {
        ascIter = other.ascIter;
        i = other.i;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    if ((this->ascIter == other.ascIter) && (this->i == other.i))
    {
        return true;
    }
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
   return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    if ((this->ascIter == other.ascIter) && (this->i < other.i))
    {
        return true;
    }
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    if ((this->ascIter == other.ascIter) && (this->i > other.i))
    {
        return true;
    }
    return false;
}

int MagicalContainer::AscendingIterator::operator*()
{
    return ascIter->magicalContainer[i];
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (this->i == this->end().i)
    {
        throw std::runtime_error("This is the last element");
    }
    ++i;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return *this;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator iter;
    iter.ascIter = ascIter;
    iter.i =ascIter->magicalContainer.size();
    return iter;
}

// SideCross Iterator
// Constructors
MagicalContainer::SideCrossIterator::SideCrossIterator() : crossIter(nullptr), i(0) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : crossIter(other.crossIter), i(other.i) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicalContainer) : crossIter(&magicalContainer), i(0) {}
MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

// Operators
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this->crossIter != other.crossIter)
    {
        throw runtime_error("These are different containers");
    }

    if (this != &other)
    {
        crossIter = other.crossIter;
        i = other.i;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if ((this->crossIter == other.crossIter) && (this->i == other.i))
    {
        return true;
    }
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
   return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    if ((this->crossIter == other.crossIter) && (this->i < other.i))
    {
        return true;
    }
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    if ((this->crossIter == other.crossIter) && (this->i > other.i))
    {
        return true;
    }
    return false;
}

int MagicalContainer::SideCrossIterator::operator*()
{
    return crossIter->magicalContainer[i];
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (i == crossIter->magicalContainer.size())
    {
        throw std::runtime_error("This is the last element");
    }

    if (this->i == (crossIter->magicalContainer.size() / 2))
    {
        i = crossIter->magicalContainer.size();
        return *this;
    }

    else if (this->i > (crossIter->magicalContainer.size() / 2))
    {
        i = crossIter->magicalContainer.size() - i;
        return *this;
    }

    else
    {
        i = crossIter->magicalContainer.size() - i - 1;
        return *this;
    }
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    this->i = 0;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator iter;
    iter.crossIter = crossIter;
    iter.i =crossIter->magicalContainer.size();
    return iter;
}

// Prime Iterator
// Constructors
MagicalContainer::PrimeIterator::PrimeIterator() : primeIter(nullptr), i(0) {}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : primeIter(other.primeIter), i(other.i) {}
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicalContainer) : primeIter(&magicalContainer), i(0) {}
MagicalContainer::PrimeIterator::~PrimeIterator() {}

// Operators
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this->primeIter != other.primeIter)
    {
        throw runtime_error("These are different containers");
    }

    if (this != &other)
    {
        primeIter = other.primeIter;
        i = other.i;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    if ((this->primeIter == other.primeIter) && (this->i == other.i))
    {
        return true;
    }
    return false;
}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    if ((this->primeIter == other.primeIter) && (this->i < other.i))
    {
        return true;
    }
    return false;
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    if ((this->primeIter == other.primeIter) && (this->i > other.i))
    {
        return true;
    }
    return false;
}

int MagicalContainer::PrimeIterator::operator*()
{
    return *primeIter->primeMagicalContainer[i];
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (this->i == this->end().i)
    {
        throw std::runtime_error("This is the last element");
    }
    ++this->i;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator iter;
    iter.primeIter = primeIter;
    iter.i = primeIter->primeMagicalContainer.size();
    return iter;
}
