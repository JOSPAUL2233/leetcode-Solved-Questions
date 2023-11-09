<h2><a href="https://leetcode.com/problems/number-of-substrings-with-only-1s/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1513. Number of Substrings With Only 1s</a></h2><h3>Medium</h3><hr><div><p>Given a binary string <code>s</code>, return <em>the number of substrings with all characters</em> <code>1</code><em>'s</em>. Since the answer may be too large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "0110111"
<strong>Output:</strong> 9
<strong>Explanation:</strong> There are 9 substring in total with only 1's characters.
"1" -&gt; 5 times.
"11" -&gt; 3 times.
"111" -&gt; 1 time.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "101"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Substring "1" is shown 2 times in s.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "111111"
<strong>Output:</strong> 21
<strong>Explanation:</strong> Each substring contains only 1's characters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>
</div>