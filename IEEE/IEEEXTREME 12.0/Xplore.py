import sys;
import json;

input = sys.stdin.readlines();

n = int(input[0]);

by_authors = {};
for i in range(1, len(input)):
  obj = json.loads(input[i]);
  citations = obj['citing_paper_count'];
  for author in obj['authors']['authors']:
    name = author['full_name'];
    if name not in by_authors:
      by_authors[name] = [];
    by_authors[name].append(citations);

to_sort = [];
for author in by_authors.keys():
  values = by_authors[author];
  values.sort();
  values.reverse();
  h_index = 0;
  for i in range(len(values)):
    if values[i] >= i+1:
      h_index = i+1;
  to_sort.append([author, h_index]);

def own_cmp(a, b):
  if a[1] != b[1]:
    if a[1] > b[1]:
      return -1;
    if a[1] < b[1]:
      return 1;
  if a[0] < b[0]:
    return -1;
  if a[0] > b[0]:
    return 1;
  return 0;

to_sort = sorted(to_sort, cmp=own_cmp);

for i in range(len(to_sort)):
  print str(to_sort[i][0]), to_sort[i][1];
