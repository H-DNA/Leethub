class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        if len(cards) == 1 and abs(cards[0] - 24) < 1e-5:
            return True
        for i in range(0, len(cards)):
            val_i = cards[i]
            cards.pop(i)
            for j in range(0, len(cards)):
                val_j = cards[j]
                cards.pop(j)

                cards.append(val_i * val_j)
                if self.judgePoint24(cards):
                    return True
                cards.pop()

                if val_j != 0:
                    cards.append(val_i / val_j)
                    if self.judgePoint24(cards):
                        return True
                    cards.pop()

                cards.append(val_i - val_j)
                if self.judgePoint24(cards):
                    return True
                cards.pop()

                cards.append(val_i + val_j)
                if self.judgePoint24(cards):
                    return True
                cards.pop()

                cards.insert(j, val_j)
            cards.insert(i, val_i)
        return False