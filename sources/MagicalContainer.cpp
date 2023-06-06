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
    for (size_t i = 0; i < magicalContainer.size(); i++)
    {
        if (isPrime(num))
        {
            if (num < *primeMagicalContainer[i])
            {
                int temp = *primeMagicalContainer[i];
                *primeMagicalContainer[i] = num;
                num = temp;
            }
            primeMagicalContainer.emplace_back(num);
        }
        if (num < magicalContainer[i])
        {
            int temp = magicalContainer[i];
            magicalContainer[i] = num;
            num = temp;
        }
        magicalContainer.emplace_back(num);
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
    if (!(this == &other))
    {
        return true;
    }
    return false;
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
    return this->ascIter->magicalContainer[i];
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++()
{
    if (this->i == this->end().i)
    {
        throw std::runtime_error("This is the last element");
    }
    ++this->i;
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
    iter.i = ascIter->size();
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
    if (!(this == &other))
    {
        return true;
    }
    return false;
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
    return this->crossIter->magicalContainer[i];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++()
{
    if (this->i == this->end().i)
    {
        throw std::runtime_error("This is the last element");
    }

    if (i < crossIter->size() - 1)
    {
        if (i % 2 == 0)
        {
            i = (i + 1) / 2;
        }
        else
        {
            i = crossIter->size() - 1 - i / 2;
        }
    }
    else
    {
        i = crossIter->size();
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
    iter.i = crossIter->size() / 2;
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
    if (!(this == &other))
    {
        return true;
    }
    return false;
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
    return this->primeIter->magicalContainer[i];
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++()
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
    iter.i = primeIter->size();
    return iter;
}
