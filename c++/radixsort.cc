// Implementation of Radix Sort on strings.
#include "radixsort.hh"
#include <algorithm>

using namespace std;

/* This is a pretty crummy Radix Sort because the continual copying of
   the string pointers and allocation of the buckets.  It's faster
   than the built-in qsort with strcmp though.

   This is a *stable* sort with running time O(nm) where n is the
   number of strings and m is the *average* of the lengths of the
   largest common prefix that each string shares with any other
   string.

   The major vulnerability of this algorithm is that it consumes a lot
   of memory, specifically it requires (sizeof(char *) + sizeof(int))
   * 256 * L bytes where L is the length of the largest common prefix
   that any two strings share.
*/
void radixsort(vector<const char *>& stuff, int depth)
{
  if (stuff.size() < 2)
    return;

  vector<const char *> buckets[256];
  
  for (int i = 0; i < stuff.size(); i++)
    buckets[stuff[i][depth]].push_back(stuff[i]);

  for (int i = 1; i < 256; i++)
    radixsort(buckets[i], depth + 1);
  
  stuff.clear();
  for (int i = 0; i < 256; i++)
    copy(buckets[i].begin(), buckets[i].end(),
         back_inserter(stuff));
}
