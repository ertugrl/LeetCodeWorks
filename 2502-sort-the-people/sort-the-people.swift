class Solution {
    func sortPeople(_ names: [String], _ heights: [Int]) -> [String] {
        let n = names.count
        var indices: [Int] = Array(0..<n)

        indices = indices.sorted(by: {lhs, rhs in
            heights[lhs] > heights[rhs]
        })

        var sortedNames: [String] = []
        for idx in 0..<n {
            sortedNames.append(names[indices[idx]])
        }

        return sortedNames
    }
}