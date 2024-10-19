<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Majority Element Finder</title>
</head>
<body>
    <h1>Majority Element Finder</h1>
    <script>
        function majorityElement(nums) {
            let freq = 0, candidate = null;

            for (let num of nums) {
                if (freq === 0) {
                    candidate = num;
                }
                freq += (num === candidate) ? 1 : -1;
            }

            // Verify the candidate
            let count = 0;
            for (let num of nums) {
                if (num === candidate) {
                    count++;
                }
            }

            return count > nums.length / 2 ? candidate : null;
        }

        function main() {
            const n = parseInt(prompt("Enter the number of votes: "), 10);

            if (n <= 0) {
                alert("Invalid number of votes. Please enter a positive number.");
                return;
            }

            const votes = prompt("Enter the votes (numbers separated by space): ");
            const nums = votes.split(' ').map(Number);

            if (nums.length !== n) {
                alert("The number of votes does not match the specified count.");
                return;
            }

            const ans = majorityElement(nums);

            if (ans !== null) {
                alert("The Majority Element is: " + ans);
            } else {
                alert("No Majority Element found.");
            }
        }

        main();
    </script>
</body>
</html>

