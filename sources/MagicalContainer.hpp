#pragma once
#include <stdio.h>
#include <vector>


using namespace std;
namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> magicalContainer;
        vector<int*> primeMagicalContainer;

    public:
        void addElement(int num);
        void removeElement(int num);
        int size();
        MagicalContainer();
        ~MagicalContainer();

        class AscendingIterator
        {
        private:
            MagicalContainer *ascIter;
            int i;

        public:
            AscendingIterator();
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(MagicalContainer &magicalContainer);
            ~AscendingIterator();
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int operator*();
            AscendingIterator operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer *crossIter;
            int i;

        public:
            SideCrossIterator();
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(MagicalContainer &magicalContainer);
            ~SideCrossIterator();
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int operator*();
            SideCrossIterator operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer *primeIter;
            int i;

        public:
            PrimeIterator();
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(MagicalContainer &magicalContainer);
            ~PrimeIterator();
            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int operator*();
            PrimeIterator operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}