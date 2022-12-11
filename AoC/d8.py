from aocd import get_data


class Solution():
    def __init__(self):
        self.data = get_data(day=8, year=2022).splitlines()
        self.count = len(self.data[1:-1])*2 + len(self.data[0])*2 
        self.scores = []
        self.parse_trees()

    def parse_trees(self):
        for rowidx, _row in enumerate(self.data[1:-1],1):
            for treeidx, tree in enumerate(_row[1:-1], 1):
                row_left = [tree > x for x in _row[:treeidx]]
                row_right = [ tree > x for x in _row[treeidx+1:]]
                column_top = [tree > x[treeidx] for x in self.data[:rowidx] ]
                column_bottom = [tree > x[treeidx] for x in self.data[rowidx+1:]]
                
                if any(map(all, [row_left, row_right, column_top, column_bottom])):
                    self.count += 1

                score = self.viewable_trees(row_left[::-1]) * self.viewable_trees(row_right) * self.viewable_trees(column_top[::-1]) * self.viewable_trees(column_bottom)
                self.scores.append(score)

    def viewable_trees(self, trees):
        count = 0

        for x in trees:
            count += 1
            if not x:
                break
        return count

if __name__ == '__main__':
    solution = Solution()
    print(f'Solution for part one: {solution.count}')
    print(f'Solution for part two: {max(solution.scores)}')
