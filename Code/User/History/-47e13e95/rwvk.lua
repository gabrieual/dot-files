local function longest_commun_subsequence(word_a, word_b, table)

    for i = 1, #word_a do
l                    table[i][j] = table[i - 1][j]
                elseif (j>1) then
                    table[i][j] = table[i][j -1]
                end
            end
        end
    end
    return table
end

local function longest_commun_substring(word_a, word_b, table)
    
end

local word_a = "fish"
local word_b = "fosh"

local matrix = {}
for i = 1, #word_a do
    table.insert(matrix, {})
    for j = 0, #word_b do
        table[i] = 0
    end
end

local response_table = longest_commun_subsequence(word_a, word_b, table)
print(response_table[#word_a][#word_b])