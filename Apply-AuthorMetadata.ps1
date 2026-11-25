# 作者：南京大学24届沈逸文
# Add metadata only; never modify the primary file stream.
$authorText = '南京大学24届沈逸文'
$packageRoot = $PSScriptRoot
$attributionCount = 0
foreach ($attributedFile in Get-ChildItem -LiteralPath $packageRoot -Recurse -File) {
    Set-Content -LiteralPath $attributedFile.FullName -Stream Author -Value $authorText -Encoding utf8 -NoNewline
    $attributionCount++
}
Write-Output "已为 $attributionCount 个文件恢复作者元数据：$authorText"
