<?php

/**
 * @file
 * Bellcom webform address autocomplete component.
 */

module_load_include('inc', 'webform', 'components/textfield');

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_address_autocomp() {
  $defaults = _webform_defaults_textfield();
  $defaults['extra']['mode'] = '';
  return $defaults;
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_address_autocomp($component) {
  $form = _webform_edit_textfield($component);

  $form['extra']['mode'] = array(
    '#type' => 'radios',
    '#title' => t('Autocomplete mode'),
    '#required' => TRUE,
    '#default_value' => ($component['extra']['mode']) ? $component['extra']['mode'] : 'address',
    '#options' => array(
      'address' => t('Adresse'),
      'block' => t('Ejerlav'),
      'matrikula' => t('Jordstykker'),
    ),
  );

  return $form;
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_address_autocomp($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $element = _webform_render_textfield($component, $value, $filter, $submission);

  $mode = $component['extra']['mode'];
  if (!$mode) {
    $mode = 'address';
  }

  $element['#autocomplete_path'] = "bellcom_webform_address_autocomplete/$mode";

  return $element;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_address_autocomp($component, $value, $format = 'html', $submission = array()) {
  return _webform_display_textfield($component, $value, $format, $submission);
}

/**
 * Implements _webform_analysis_component().
 */
function _webform_analysis_address_autocomp($component, $sids = array(), $single = FALSE, $join = NULL) {
  return _webform_analysis_textfield($component, $sids, $single, $join);
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_address_autocomp($component, $value) {
  return _webform_table_textfield($component, $value);
}

/**
 * Implements _webform_action_set_component().
 */
function _webform_action_set_address_autocomp($component, &$element, &$form_state, $value) {
  _webform_action_set_textfield($component, $element, $form_state, $value);
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_address_autocomp($component, $export_options) {
  return _webform_csv_headers_textfield($component, $export_options);
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_address_autocomp($component, $export_options, $value) {
  return _webform_csv_data_textfield($component, $export_options, $value);
}