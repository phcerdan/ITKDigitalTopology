itk_module_test()

set(DigitalTopologyTests
  itkMinimalStandardRandomVariateGeneratorTest.cxx
  itkNormalDistributionImageSourceTest.cxx
  itkSpelClassificationTest.cxx
  )

CreateTestDriver(DigitalTopology "${DigitalTopology-Test_LIBRARIES}" "${DigitalTopologyTests}")

itk_add_test(NAME itkMinimalStandardRandomVariateGeneratorTest
  COMMAND DigitalTopologyTestDriver itkMinimalStandardRandomVariateGeneratorTest
  )

itk_add_test(NAME itkSpelClassificationTest
  COMMAND DigitalTopologyTestDriver
    --compare
    ${ITK_TEST_OUTPUT_DIR}/itkSpelClassificationTestOutput.mha
    DATA{Baseline/itkSpelClassificationTestOutput.mha}
  itkSpelClassificationTest
    ${ITK_TEST_OUTPUT_DIR}/itkSpelClassificationTestOutput.mha
  )

itk_add_test(NAME itkNormalDistributionImageSourceTest
  COMMAND DigitalTopologyTestDriver --without-threads
  --compare
    ${ITK_TEST_OUTPUT_DIR}/itkNormalDistributionImageSourceTestOutput.mha
    DATA{Baseline/itkNormalDistributionImageSourceTestOutput.mha}
  itkNormalDistributionImageSourceTest
    ${ITK_TEST_OUTPUT_DIR}/itkNormalDistributionImageSourceTestOutput.mha
  )
